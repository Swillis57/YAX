#ifndef _EFFECT_PARAMETER_H
#define _EFFECT_PARAMETER_H

#include <memory>
#include <string>
#include <vector>
#include "EffectParameterClass.h"
#include "EffectParameterType.h"
#include "../../../external/glew/include/GL/glew.h"
#include "../Utils.h"

namespace YAX		
{
    struct Matrix;
    struct Quaternion;
    class Texture;
    class Texture2D;
    class Texture3D;
    class TextureCube;
    struct Vector2;
    struct Vector3;
    struct Vector4;
    
    class EffectParameter
    {
        friend class Effect;

    public:
        EffectParameter(
            GLuint prog,
            std::string name,
            EffectParameterClass,
            EffectParameterType,
            i32 rowCount,
            i32 colCount
        );

        i32 ColumnCount() const;
        std::string Name() const;
        EffectParameterClass ParameterClass() const;
        EffectParameterType ParameterType() const;

        bool GetValueBool() const;
        i32 GetValueInt32() const;
        Matrix GetValueMatrix(bool transpose) const;
        Quaternion GetValueQuaternion() const;
        float GetValueSingle() const;
        Texture2D* GetValueTexture2D() const;
        Texture3D* GetValueTexture3D() const;
        TextureCube* GetValueTextureCube() const;
        Vector2 GetValueVector2() const;
        Vector3 GetValueVector3() const;
        Vector4 GetValueVector4() const;

        std::vector<bool> GetValueBoolArray(i32 count) const;
        std::vector<i32> GetValueInt32Array(i32 count) const;
        std::vector<Matrix> GetValueMatrixArray(i32 count, bool transpose) const;
        std::vector<Quaternion> GetValueQuaternionArray(i32 count) const;
        std::vector<float> GetValueSingleArray(i32 count) const;
        std::vector<Vector2> GetValueVector2Array(i32 count) const;
        std::vector<Vector3> GetValueVector3Array(i32 count) const;
        std::vector<Vector4> GetValueVector4Array(i32 count) const;


        void SetValue(bool);
        void SetValue(i32);
        void SetValue(const Matrix&, bool transpose);
        void SetValue(const Quaternion&);
        void SetValue(float);
        void SetValue(Texture&, GLuint texUnit);
        void SetValue(const Vector2&);
        void SetValue(const Vector3&);
        void SetValue(const Vector4&);
  
        void SetValue(const std::vector<ui32>&);
        void SetValue(const std::vector<i32>&);
        void SetValue(const std::vector<Matrix>&, bool transpose);
        void SetValue(const std::vector<Quaternion>&);
        void SetValue(const std::vector<float>&);
        void SetValue(const std::vector<Vector2>&);
        void SetValue(const std::vector<Vector3>&);
        void SetValue(const std::vector<Vector4>&);

    private:
        template<typename T>
        std::unique_ptr<T[]> GetData() const;
        
        Matrix AssembleMatrix(float*) const;
        void FindMatrixUploadFunc(const Matrix&, i32 count, bool transpose) const;

        GLint _loc;
        GLuint _progID;
        i32 _colCount, _rowCount;
        std::string _name;
        EffectParameterClass _epc;
        EffectParameterType _ept;
        Texture* _tex;
        ui32 _texUnit;
    };
}


#endif