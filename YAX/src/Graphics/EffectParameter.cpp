#include "../../include/Graphics/EffectParameter.h"

#include <exception>
#include "../../include/Matrix.h"
#include "../../include/Quaternion.h"
#include "../../include/Graphics/Texture.h"
#include "../../include/Vector2.h"
#include "../../include/Vector3.h"
#include "../../include/Vector4.h"

namespace YAX
{

    EffectParameter::EffectParameter(
        GLuint prog,
        std::string name, 
        EffectParameterClass epc, 
        EffectParameterType ept, 
        i32 rowCount, 
        i32 colCount
    )
        :_name(name),
        _progID(prog),
        _epc(epc),
        _ept(ept),
        _rowCount(rowCount),
        _colCount(colCount),
        _tex(nullptr)
    {
        _loc = glGetUniformLocation(prog, name.c_str());
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

    template<> std::unique_ptr<i32[]> EffectParameter::GetData() const
    {
        std::unique_ptr<i32[]> data = std::make_unique<i32[]>(_rowCount * _colCount);
        glGetUniformiv(_progID, _loc, data.get());

        return data;
    }

    template<> std::unique_ptr<ui32[]> EffectParameter::GetData() const
    {
        std::unique_ptr<ui32[]> data = std::make_unique<ui32[]>(_rowCount * _colCount);
        glGetUniformuiv(_progID, _loc, data.get());

        return data;
    }

    template<> std::unique_ptr<float[]> EffectParameter::GetData() const
    {
        std::unique_ptr<float[]> data = std::make_unique<float[]>(_rowCount * _colCount);
        glGetUniformfv(_progID, _loc, data.get());

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

    void EffectParameter::FindMatrixUploadFunc(const Matrix& m, i32 count, bool transpose) const
    {
        //If the user requested the matrix to be transposed, then it will be in column-major
        //order (default for OpenGL)
        bool shouldTranspose = !transpose;

        if (_colCount == 2)
        {
            if (_rowCount == 2)
            {
                glUniformMatrix2fv(_loc, count, shouldTranspose, (float*)&m);
            }
            else if (_rowCount == 3)
            {
                glUniformMatrix2x3fv(_loc, count, shouldTranspose, (float*)&m);
            }
            else if (_rowCount == 4)
            {
                glUniformMatrix2x4fv(_loc, count, shouldTranspose, (float*)&m);
            }
        }
        else if (_colCount == 3)
        {
            if (_rowCount == 2)
            {
                glUniformMatrix3x2fv(_loc, count, shouldTranspose, (float*)&m);
            }
            else if (_rowCount == 3)
            {
                glUniformMatrix3fv(_loc, count, shouldTranspose, (float*)&m);
            }
            else if (_rowCount == 4)
            {
                glUniformMatrix3x4fv(_loc, count, shouldTranspose, (float*)&m);
            }
        }
        else if (_colCount == 4)
        {
            if (_rowCount == 2)
            {
                glUniformMatrix4x2fv(_loc, count, shouldTranspose, (float*)&m);
            }
            else if (_rowCount == 3)
            {
                glUniformMatrix4x3fv(_loc, count, shouldTranspose, (float*)&m);
            }
            else if (_rowCount == 4)
            {
                glUniformMatrix4fv(_loc, count, shouldTranspose, (float*)&m);
            }
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
        if (_epc != EffectParameterClass::Matrix)
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
        if (!_tex)
            throw std::runtime_error("This effect parameter is not a texture.");

        return reinterpret_cast<Texture2D*>(_tex);
    }

    Texture3D* EffectParameter::GetValueTexture3D() const
    {
        if (!_tex)
            throw std::runtime_error("This effect parameter is not a texture.");

        return reinterpret_cast<Texture3D*>(_tex);
    }

    TextureCube* EffectParameter::GetValueTextureCube() const
    {
        if (!_tex)
            throw std::runtime_error("This effect parameter is not a texture.");

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
        if (_ept != EffectParameterType::Vector3)
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

        auto data = GetData<i32>();
        std::vector<i32> vec(count);
        vec.assign(data.get(), data.get() + vec.size());
        
        return vec;
    }

    std::vector<Matrix> EffectParameter::GetValueMatrixArray(i32 count, bool transpose) const
    {
        if (_epc != EffectParameterClass::Matrix)
            throw std::runtime_error("Cannot convert the value of the effect parameter to Matrix.");

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

        auto data = GetData<float>();
        std::vector<float> vec(count);
        vec.assign(data.get(), data.get() + count);

        return vec;
    }

    std::vector<Vector2> EffectParameter::GetValueVector2Array(i32 count) const
    {
        if (_ept != EffectParameterType::Vector2)
            throw std::runtime_error("Cannot convert the value of the effect parameter to Vector2.");

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

        glUniform1i(_loc, b);
    }

    void EffectParameter::SetValue(i32 i)
    {
        if (_ept != EffectParameterType::Int32)
            throw std::runtime_error("Cannot assign a value of type Int32 to this effect parameter.");

        glUniform1i(_loc, i);
    }

    void EffectParameter::SetValue(const Matrix& m, bool transpose)
    {
        if (_epc != EffectParameterClass::Matrix)
            throw std::runtime_error("Cannot assign a value of type Matrix to this effect parameter.");

        //Don't need to manually transpose, OpenGL handles it
        FindMatrixUploadFunc(m, 1, transpose);
    }

    void EffectParameter::SetValue(const Quaternion& q)
    {
        if (_ept != EffectParameterType::Vector4)
            throw std::runtime_error("Cannot assign a value of type Quaternion to this effect parameter.");

        glUniform4f(_loc, q.X, q.Y, q.Z, q.W);
    }

    void EffectParameter::SetValue(float f)
    {
        if (_epc != EffectParameterClass::Scalar || _ept != EffectParameterType::Single)
            throw std::runtime_error("Cannot assign a value of type Single to this effect parameter.");

        glUniform1f(_loc, f);
    }

    void EffectParameter::SetValue(Texture& t, GLuint texUnit)
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

        glUniform2f(_loc, v.X, v.Y);
    }

    void EffectParameter::SetValue(const Vector3& v)
    {
        if (_ept != EffectParameterType::Vector3)
            throw std::runtime_error("Cannot assign a value of type Vector3 to this effect parameter.");

        glUniform3f(_loc, v.X, v.Y, v.Z);
    }

    void EffectParameter::SetValue(const Vector4& v)
    {
        if (_ept != EffectParameterType::Vector4)
            throw std::runtime_error("Cannot assign a value of type Vector4 to this effect parameter.");

        glUniform4f(_loc, v.X, v.Y, v.Z, v.W);
    }

    void EffectParameter::SetValue(const std::vector<ui32>& vec)
    {
        if (_ept != EffectParameterType::Bool || _ept != EffectParameterType::Int32 || _epc != EffectParameterClass::Array)
            throw std::runtime_error("Cannot assign an array of type bool to this effect parameter.");

        glUniform1uiv(_loc, vec.size(), (const GLuint*)&vec[0]);
    }

    void EffectParameter::SetValue(const std::vector<i32>& vec)
    {
        if (_ept != EffectParameterType::Int32 || _epc != EffectParameterClass::Array)
            throw std::runtime_error("Cannot assign an array of type Int32 to this effect parameter.");

        glUniform1iv(_loc, vec.size(), (const GLint*)&vec[0]);
    }
    
    void EffectParameter::SetValue(const std::vector<Matrix>& vec, bool transpose)
    {
        if (_epc != EffectParameterClass::Matrix)
            throw std::runtime_error("Cannot assign an array of type Matrix to this effect parameter.");

        FindMatrixUploadFunc(vec[0], vec.size(), transpose);
    }

    void EffectParameter::SetValue(const std::vector<Quaternion>& vec)
    {
        if (_ept != EffectParameterType::Vector4 || _epc != EffectParameterClass::Array)
            throw std::runtime_error("Cannot assign an array of type Quaternion to this effect parameter.");
        
        glUniform4fv(_loc, vec.size(), (float*)&vec[0]);
    }

    void EffectParameter::SetValue(const std::vector<float>& vec)
    {
        if (_ept != EffectParameterType::Single || _epc != EffectParameterClass::Array)
            throw std::runtime_error("Cannot assign an array of type Single to this effect parameter.");

        glUniform1fv(_loc, vec.size(), (float*)&vec[0]);
    }

    void EffectParameter::SetValue(const std::vector<Vector2>& vec)
    {
        if (_ept != EffectParameterType::Vector2 || _epc != EffectParameterClass::Array)
            throw std::runtime_error("Cannot assign an array of type Vector2 to this effect parameter.");

        glUniform2fv(_loc, vec.size(), (float*)&vec[0]);
    }

    void EffectParameter::SetValue(const std::vector<Vector3>& vec)
    {
        if (_ept != EffectParameterType::Vector3 || _epc != EffectParameterClass::Array)
            throw std::runtime_error("Cannot assign an array of type Vector3 to this effect parameter.");

        glUniform3fv(_loc, vec.size(), (float*)&vec[0]);
    }

    void EffectParameter::SetValue(const std::vector<Vector4>& vec)
    {
        if (_ept != EffectParameterType::Vector4 || _epc != EffectParameterClass::Array)
            throw std::runtime_error("Cannot assign an array of type Vector4 to this effect parameter.");

        glUniform4fv(_loc, vec.size(), (float*)&vec[0]);
    }
}