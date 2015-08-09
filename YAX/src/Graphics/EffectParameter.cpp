#include "Graphics/EffectParameter.h"

#include <cstdlib>
#include <exception>
#include "Matrix.h"
#include "Quaternion.h"
#include "Graphics/Texture.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

namespace YAX
{
    EffectParameter::EffectParameter(
        GLuint prog,
        std::string name, 
        EffectParameterClass epc, 
        EffectParameterType ept, 
        i32 rowCount, 
        i32 colCount,
        i32 numElements
    ) :_name(name),
        _progID(prog),
        _epc(epc),
        _ept(ept),
        _rowCount(rowCount),
        _colCount(colCount),
        _numElements(numElements),
        _tex(nullptr),
        _texUnit(0),
        _transpose(false),
        _value(std::make_unique<unsigned char[]>(_rowCount * _colCount * _numElements * sizeof(float))),
        _rawPtr(_value.get())
    {
        _loc = glGetUniformLocation(prog, name.c_str());

        SelectApplyCallback();
    }

    i32 EffectParameter::ColumnCount() const
    {
        return _colCount;
    }

    std::string EffectParameter::Name() const
    {
        return _name;
    }

    EffectParameterClass EffectParameter::ParameterClass() const
    {
        return _epc;
    }

    EffectParameterType EffectParameter::ParameterType() const
    {
        return _ept;
    }

    template<typename T> 
    std::unique_ptr<T[]> EffectParameter::GetData() const
    {
        std::unique_ptr<T[]> data = std::make_unique<T[]>(_rowCount * _colCount);
        std::memcpy(data.get(), _rawPtr, _rowCount * _colCount * sizeof(T));

        return data;
    }

    Matrix EffectParameter::AssembleMatrix(float* data) const
    {
        if (_rowCount == 2 && _colCount == 2)
        {
            return Matrix
            {
                data[0], data[1], 0.0f, 0.0f,
                data[2], data[3], 0.0f, 0.0f,
                  0.0f,     0.0f, 0.0f, 0.0f,
                  0.0f,     0.0f, 0.0f, 0.0f
            };
        }
        else if (_rowCount == 3 && _colCount == 3)
        {
            return Matrix
            {
                data[0], data[1], data[2], 0.0f,
                data[3], data[4], data[5], 0.0f,
                data[6], data[7], data[8], 0.0f,
                   0.0f,    0.0f,    0.0f, 0.0f
            };
        }
        else if (_rowCount == 4 && _colCount == 4)
        {
            return Matrix
            {
                 data[0],  data[1],  data[2],  data[3],
                 data[4],  data[5],  data[6],  data[7],
                 data[8],  data[9], data[10], data[11],
                data[12], data[13], data[14], data[15],
            };
        }
        else if ((_rowCount == 2 && _colCount == 3)
            || (_rowCount == 3 && _colCount == 2))
        {
            //Build it as a 2x3, then check to see if it's actually a 3x2 
            //and flip it before returning
            Matrix m
            {
                 data[0],  data[1],  data[2], 0.0f,
                 data[3],  data[4],  data[5], 0.0f,
                    0.0f,     0.0f,     0.0f, 0.0f,
                    0.0f,     0.0f,     0.0f, 0.0f,
            };

            return (_rowCount == 3 ? Matrix::Transpose(m) : m);
        }
        else if ((_rowCount == 2 && _colCount == 4)
            || (_rowCount == 4 && _colCount == 2))
        {
            //Build it as a 2x4, then check to see if it's actually a 4x2 
            //and flip it before returning
            Matrix m
            {
                 data[0],  data[1],  data[2], data[3],
                 data[4],  data[5],  data[6], data[7],
                    0.0f,     0.0f,     0.0f,    0.0f,
                    0.0f,     0.0f,     0.0f,    0.0f,
            };

            return (_rowCount == 4 ? Matrix::Transpose(m) : m);
        }
        else if ((_rowCount == 3 && _colCount == 4)
            || (_rowCount == 4 && _colCount == 3))
        {
            //Build it as a 3x4, then check to see if it's actually a 4x3 
            //and flip it before returning
            Matrix m
            {
                 data[0], data[1],  data[2],  data[3],
                 data[4], data[5],  data[6],  data[7],
                 data[8], data[9], data[10], data[11],
                    0.0f,    0.0f,    0.0f,      0.0f,
            };

            return (_rowCount == 4 ? Matrix::Transpose(m) : m);
        }
        else
        {
            throw std::runtime_error("Invalid matrix size.");
        }
    }

    void EffectParameter::SelectMatrixUploadFunc(float* m, i32 count) 
    {
        //If the user requested the matrix to be transposed, then it will be in column-major
        //order (default for OpenGL)
        //bool shouldTranspose = !transpose;

        if (_colCount == 2)
        {
            if (_rowCount == 2)
            {
                _applyFunc = [this, m, count] { glUniformMatrix2fv(_loc, count, !_transpose, m); };
            }
            else if (_rowCount == 3)
            {
                _applyFunc = [this, m, count] { glUniformMatrix2x3fv(_loc, count, !_transpose, m); };
            }
            else if (_rowCount == 4)
            {
                _applyFunc = [this, m, count] { glUniformMatrix2x4fv(_loc, count, !_transpose, m); };
            }
        }
        else if (_colCount == 3)
        {
            if (_rowCount == 2)
            {
                _applyFunc = [this, m, count] { glUniformMatrix3x2fv(_loc, count, !_transpose, m); };
            }
            else if (_rowCount == 3)
            {
                _applyFunc = [this, m, count] { glUniformMatrix3fv(_loc, count, !_transpose, m); };
            }
            else if (_rowCount == 4)
            {
                _applyFunc = [this, m, count] { glUniformMatrix3x4fv(_loc, count, !_transpose, m); };
            }
        }
        else if (_colCount == 4)
        {
            if (_rowCount == 2)
            {
                _applyFunc = [this, m, count] { glUniformMatrix4x2fv(_loc, count, !_transpose, m); };
            }
            else if (_rowCount == 3)
            {
                _applyFunc = [this, m, count] { glUniformMatrix4x3fv(_loc, count, !_transpose, m); };
            }
            else if (_rowCount == 4)
            {
                _applyFunc = [this, m, count] { glUniformMatrix4fv(_loc, count, !_transpose, m); };
            }
        }
    }

    void EffectParameter::SelectApplyCallback()
    {
        auto* ptr = reinterpret_cast<float*>(_rawPtr);

        switch (_epc)
        {
            //Textures get assigned to their units in GraphicsDevice, so don't do anything here.
            case EffectParameterClass::Texture:
                _applyFunc = [this] { _tex->Bind(_texUnit); };
                break;

            case EffectParameterClass::Scalar:
                switch (_ept)
                {
                    case EffectParameterType::Bool:
                    case EffectParameterType::Int32:
                        _applyFunc = [this] { glUniform1i(_loc, *reinterpret_cast<i32*>(_rawPtr)); };
                        break;
                    
                    case EffectParameterType::Matrix:
                        SelectMatrixUploadFunc(reinterpret_cast<float*>(_rawPtr), 1);
                        break;
                    
                    case EffectParameterType::Single:
                        _applyFunc = [this, ptr] { glUniform1f(_loc, *ptr); };
                        break;

                    case EffectParameterType::Vector2:
                        _applyFunc = [this, ptr] { glUniform2f(_loc, ptr[0], ptr[1]); };
                        break;
                    
                    case EffectParameterType::Vector3:
                        _applyFunc = [this, ptr] { glUniform3f(_loc, ptr[0], ptr[1], ptr[2]); };
                        break;
                    
                    case EffectParameterType::Vector4:
                        _applyFunc = [this, ptr] { glUniform4f(_loc, ptr[0], ptr[1], ptr[2], ptr[3]); };
                        break;
                }
                break;
            case EffectParameterClass::Array:
                switch (_ept)
                {
                    case EffectParameterType::Bool:
                    case EffectParameterType::Int32:
                        _applyFunc = [this] { glUniform1iv(_loc, _rowCount * _colCount, reinterpret_cast<i32*>(_rawPtr)); };
                        break;

                    case EffectParameterType::Matrix:
                        SelectMatrixUploadFunc(reinterpret_cast<float*>(_rawPtr), _rowCount * _colCount);
                        break;

                    case EffectParameterType::Single:
                        _applyFunc = [this] { glUniform1fv(_loc, _rowCount * _colCount, reinterpret_cast<float*>(_rawPtr)); };
                        break;

                    case EffectParameterType::Vector2:
                        _applyFunc = [this] { glUniform2fv(_loc, _rowCount * _colCount, reinterpret_cast<float*>(_rawPtr)); };
                        break;

                    case EffectParameterType::Vector3:
                        _applyFunc = [this] { glUniform3fv(_loc, _rowCount * _colCount, reinterpret_cast<float*>(_rawPtr)); };
                        break;

                    case EffectParameterType::Vector4:
                        _applyFunc = [this] { glUniform4fv(_loc, _rowCount * _colCount, reinterpret_cast<float*>(_rawPtr)); };
                        break;
                }
                break;
        }
    }

    bool EffectParameter::GetValueBool() const
    {
        if (_ept != EffectParameterType::Bool || _ept != EffectParameterType::Int32)
            throw std::runtime_error("Cannot convert the value of the effect parameter to bool.");

        return GetData<i32>()[0] != 0;
    }

    i32 EffectParameter::GetValueInt32() const
    {
        if (_ept != EffectParameterType::Bool || _ept != EffectParameterType::Int32)
            throw std::runtime_error("Cannot convert the value of the effect parameter to Int32.");

        return GetData<i32>()[0];
    }
    
    Matrix EffectParameter::GetValueMatrix(bool transpose) const
    {
        if (_ept != EffectParameterType::Matrix)
            throw std::runtime_error("Cannot convert the value of the effect parameter to Matrix.");

        auto data = GetData<float>();
        return AssembleMatrix(data.get());
    }

    Quaternion EffectParameter::GetValueQuaternion() const
    {
        if (_ept != EffectParameterType::Vector4)
            throw std::runtime_error("Cannot convert the value of the effect parameter to Quaternion.");

        auto data = GetData<float>();
        Quaternion q { data[0], data[1], data[2], data[3] };

        return q;
    }

    float EffectParameter::GetValueSingle() const
    {
        if (_ept != EffectParameterType::Single)
            throw std::runtime_error("Cannot convert the value of the effect parameter to Single.");

        return GetData<float>()[0];
    }

    Texture2D* EffectParameter::GetValueTexture2D() const
    {
        if (_epc != EffectParameterClass::Texture && _ept != EffectParameterType::Texture2D)
            throw std::runtime_error("This effect parameter is not a Teture2D.");

        return reinterpret_cast<Texture2D*>(_tex);
    }

    Texture3D* EffectParameter::GetValueTexture3D() const
    {
        if (_epc != EffectParameterClass::Texture && _ept != EffectParameterType::Texture3D)
            throw std::runtime_error("This effect parameter is not a Texture3D.");

        return reinterpret_cast<Texture3D*>(_tex);
    }

    TextureCube* EffectParameter::GetValueTextureCube() const
    {
        if (_epc != EffectParameterClass::Texture && _ept != EffectParameterType::TextureCube)
            throw std::runtime_error("This effect parameter is not a TextureCube.");

        return reinterpret_cast<TextureCube*>(_tex);
    }

    Vector2 EffectParameter::GetValueVector2() const
    {
        if (_ept != EffectParameterType::Vector2 || _ept != EffectParameterType::Vector4)
            throw std::runtime_error("Cannot convert the value of the effect parameter to Vector2.");

        auto data = GetData<float>();
        return Vector2 { data[0], data[1] };
    }

    Vector3 EffectParameter::GetValueVector3() const
    {
        if (_ept != EffectParameterType::Vector3 || _ept != EffectParameterType::Vector4)
            throw std::runtime_error("Cannot convert the value of the effect parameter to Vector3.");

        auto data = GetData<float>();
        return Vector3 { data[0], data[1], data[2] };
    }

    Vector4 EffectParameter::GetValueVector4() const
    {
        if (_ept != EffectParameterType::Vector4)
            throw std::runtime_error("Cannot convert the value of the effect parameter to Vector4.");

        auto data = GetData<float>();
        return Vector4 { data[0], data[1], data[2], data[3] };
    }

    std::vector<bool> EffectParameter::GetValueBoolArray(i32 count) const
    {
        if (_ept != EffectParameterType::Bool || _ept != EffectParameterType::Int32)
            throw std::runtime_error("Cannot convert the value of the effect parameter to bool.");

        auto data = GetData<i32>();
        std::vector<bool> vec(count);

        for (ui32 i = 0; i < vec.size(); i++)
        {
            vec[i] = data[i] != 0;
        }

        return vec;
    }

    std::vector<i32> EffectParameter::GetValueInt32Array(i32 count) const
    {
        if (_ept != EffectParameterType::Bool || _ept != EffectParameterType::Int32)
            throw std::runtime_error("Cannot convert the value of the effect parameter to Int32.");

        if (count <= 0 || count > _numElements)
            throw std::runtime_error("count must be greater than 0 and less than or equal to the number of elements of the EffectParameter.");

        auto data = GetData<i32>();
        std::vector<i32> vec(count);
        vec.assign(data.get(), data.get() + vec.size());
        
        return vec;
    }

    std::vector<Matrix> EffectParameter::GetValueMatrixArray(i32 count, bool transpose) const
    {
        if (_ept != EffectParameterType::Matrix)
            throw std::runtime_error("Cannot convert the value of the effect parameter to Matrix.");

        if (count <= 0 || count > _numElements)
            throw std::runtime_error("count must be greater than 0 and less than or equal to the number of elements of the EffectParameter.");

        auto data = GetData<float>();
        std::vector<Matrix> vec(count);

        float* ptr = (float*)&vec[0];
        for (i32 i = 0; i < count; i++)
        {
            vec.emplace_back(AssembleMatrix(ptr));
            ptr += _rowCount * _colCount;
        }

        return vec;
    }

    std::vector<Quaternion> EffectParameter::GetValueQuaternionArray(i32 count) const
    {
        if (_ept != EffectParameterType::Vector4)
            throw std::runtime_error("Cannot convert the value of the effect parameter to Quaternion.");

        if (count <= 0 || count > _numElements)
            throw std::runtime_error("count must be greater than 0 and less than or equal to the number of elements of the EffectParameter.");

        auto data = GetData<float>();
        Quaternion* qData = reinterpret_cast<Quaternion*>(data.get());
        std::vector<Quaternion> vec(count);
        vec.assign(qData, qData + count);
        
        return vec;
    }

    std::vector<float> EffectParameter::GetValueSingleArray(i32 count) const
    {
        if (_ept != EffectParameterType::Single)
            throw std::runtime_error("Cannot convert the value of the effect parameter to Single.");

        if (count <= 0 || count > _numElements)
            throw std::runtime_error("count must be greater than 0 and less than or equal to the number of elements of the EffectParameter.");

        auto data = GetData<float>();
        std::vector<float> vec(count);
        vec.assign(data.get(), data.get() + count);

        return vec;
    }

    std::vector<Vector2> EffectParameter::GetValueVector2Array(i32 count) const
    {
        if (_ept != EffectParameterType::Vector2)
            throw std::runtime_error("Cannot convert the value of the effect parameter to Vector2.");

        if (count <= 0 || count > _numElements)
            throw std::runtime_error("count must be greater than 0 and less than or equal to the number of elements of the EffectParameter.");

        auto data = GetData<float>();
        Vector2* vData = reinterpret_cast<Vector2*>(data.get());
        std::vector<Vector2> vec(count);
        vec.assign(vData, vData + count);

        return vec;
    }
    
    std::vector<Vector3> EffectParameter::GetValueVector3Array(i32 count) const
    {
        if (_ept != EffectParameterType::Vector3)
            throw std::runtime_error("Cannot convert the value of the effect parameter to Vector3.");

        if (count <= 0 || count > _numElements)
            throw std::runtime_error("count must be greater than 0 and less than or equal to the number of elements of the EffectParameter.");

        auto data = GetData<float>();
        Vector3* vData = reinterpret_cast<Vector3*>(data.get());
        std::vector<Vector3> vec(count);
        vec.assign(vData, vData + count);

        return vec;
    }

    std::vector<Vector4> EffectParameter::GetValueVector4Array(i32 count) const
    {
        if (_ept != EffectParameterType::Vector4)
            throw std::runtime_error("Cannot convert the value of the effect parameter to Vector4.");

        if (count <= 0 || count > _numElements)
            throw std::runtime_error("count must be greater than 0 and less than or equal to the number of elements of the EffectParameter.");

        auto data = GetData<float>();
        Vector4* vData = reinterpret_cast<Vector4*>(data.get());
        std::vector<Vector4> vec(count);
        vec.assign(vData, vData + count);

        return vec;
    }

    void EffectParameter::SetValue(bool b)
    {
        if (_ept != EffectParameterType::Bool || _ept != EffectParameterType::Int32)
            throw std::runtime_error("Cannot assign a value of type bool to this effect parameter.");

        ((bool*)_rawPtr)[0] = b;
    }

    void EffectParameter::SetValue(i32 i)
    {
        if (_ept != EffectParameterType::Int32)
            throw std::runtime_error("Cannot assign a value of type Int32 to this effect parameter.");

        ((i32*)_rawPtr)[0] = i;
    }

    void EffectParameter::SetValue(const Matrix& m, bool transpose)
    {
        if (_ept != EffectParameterType::Matrix)
            throw std::runtime_error("Cannot assign a value of type Matrix to this effect parameter.");

        std::memcpy(_rawPtr, &m, _rowCount * _colCount * sizeof(float));
        _transpose = transpose;
    }

    void EffectParameter::SetValue(const Quaternion& q)
    {
        if (_ept != EffectParameterType::Vector4)
            throw std::runtime_error("Cannot assign a value of type Quaternion to this effect parameter.");

        std::memcpy(_rawPtr, &q, 4 * sizeof(float));
    }

    void EffectParameter::SetValue(float f)
    {
        if (_epc != EffectParameterClass::Scalar || _ept != EffectParameterType::Single)
            throw std::runtime_error("Cannot assign a value of type Single to this effect parameter.");

        ((float*)_rawPtr)[0] = f;
    }

    void EffectParameter::SetValue(Texture& t, ui32 texUnit)
    {
        if (_epc != EffectParameterClass::Texture)
            throw std::runtime_error("This effect parameter is not a texture.");
        
        _tex = &t;
        _texUnit = texUnit;
    }

    void EffectParameter::SetValue(const Vector2& v)
    {
        if (_ept != EffectParameterType::Vector2)
            throw std::runtime_error("Cannot assign a value of type Vector2 to this effect parameter.");

        std::memcpy(_rawPtr, &v, 2 * sizeof(float));
    }

    void EffectParameter::SetValue(const Vector3& v)
    {
        if (_ept != EffectParameterType::Vector3)
            throw std::runtime_error("Cannot assign a value of type Vector3 to this effect parameter.");

        std::memcpy(_rawPtr, &v, 3 * sizeof(float));
    }

    void EffectParameter::SetValue(const Vector4& v)
    {
        if (_ept != EffectParameterType::Vector4)
            throw std::runtime_error("Cannot assign a value of type Vector4 to this effect parameter.");

        std::memcpy(_rawPtr, &v, 4 * sizeof(float));
    }

    void EffectParameter::SetValue(const std::vector<ui32>& vec)
    {
        if (_ept != EffectParameterType::Bool || _ept != EffectParameterType::Int32 || _epc != EffectParameterClass::Array)
            throw std::runtime_error("Cannot assign an array of type bool to this effect parameter.");

        std::memcpy(_rawPtr, &vec[0], _rowCount * _colCount * sizeof(ui32));
    }

    void EffectParameter::SetValue(const std::vector<i32>& vec)
    {
        if (_ept != EffectParameterType::Int32 || _epc != EffectParameterClass::Array)
            throw std::runtime_error("Cannot assign an array of type Int32 to this effect parameter.");

        std::memcpy(_rawPtr, &vec[0], _rowCount * _colCount * sizeof(i32));
    }
    
    void EffectParameter::SetValue(const std::vector<Matrix>& vec, bool transpose)
    {
        if (_epc != EffectParameterClass::Array && _ept != EffectParameterType::Matrix)
            throw std::runtime_error("Cannot assign an array of type Matrix to this effect parameter.");

        std::memcpy(_rawPtr, &vec[0], _rowCount * _colCount * sizeof(Matrix));
    }

    void EffectParameter::SetValue(const std::vector<Quaternion>& vec)
    {
        if (_ept != EffectParameterType::Vector4 || _epc != EffectParameterClass::Array)
            throw std::runtime_error("Cannot assign an array of type Quaternion to this effect parameter.");
        
        std::memcpy(_rawPtr, &vec[0], _rowCount * _colCount * sizeof(Quaternion));
    }

    void EffectParameter::SetValue(const std::vector<float>& vec)
    {
        if (_ept != EffectParameterType::Single || _epc != EffectParameterClass::Array)
            throw std::runtime_error("Cannot assign an array of type Single to this effect parameter.");

        std::memcpy(_rawPtr, &vec[0], _rowCount * _colCount * sizeof(float));
    }

    void EffectParameter::SetValue(const std::vector<Vector2>& vec)
    {
        if (_ept != EffectParameterType::Vector2 || _epc != EffectParameterClass::Array)
            throw std::runtime_error("Cannot assign an array of type Vector2 to this effect parameter.");

        std::memcpy(_rawPtr, &vec[0], _rowCount * _colCount * sizeof(Vector2));
    }

    void EffectParameter::SetValue(const std::vector<Vector3>& vec)
    {
        if (_ept != EffectParameterType::Vector3 || _epc != EffectParameterClass::Array)
            throw std::runtime_error("Cannot assign an array of type Vector3 to this effect parameter.");

        std::memcpy(_rawPtr, &vec[0], _rowCount * _colCount * sizeof(Vector3));
    }

    void EffectParameter::SetValue(const std::vector<Vector4>& vec)
    {
        if (_ept != EffectParameterType::Vector4 || _epc != EffectParameterClass::Array)
            throw std::runtime_error("Cannot assign an array of type Vector4 to this effect parameter.");

        std::memcpy(_rawPtr, &vec[0], _rowCount * _colCount * sizeof(Vector4));
    }
}