#ifndef _EFFECT_PARAMETER_H
#define _EFFECT_PARAMETER_H

#include <string>
#include <vector>
#include "EffectParameterCollection.h"
#include "../GLEW/glew.h"
#include "../Utils.h"

namespace XNA		
{
	enum class ParameterClass : int;
	enum class ParameterType : int;

	class Matrix;
	class Quaternion;
	class Texture2D;
	class Texture3D;
	class TextureCube;
	class Vector2;
	class Vector3;
	class Vector4;


	//EffectParameter is equivalent to a uniform in OpenGL
	class EffectParameter
	{
	public:
		EffectParameter(const std::string&);
		EffectParameter(const EffectParameter&) = default;
		EffectParameter& operator=(const EffectParameter&) = default;
		

		i32 ColumnCount();
		EffectParameterCollection Elements();
		std::string Name();
		XNA::ParameterClass ParameterClass();
		XNA::ParameterType ParameterType();
		i32 RowCount();
		std::string Semantic();
		EffectParameterCollection StructureMembers();

		template<typename ValType>
		ValType GetValue();

		template<typename ValType>
		void SetValue(ValType);

		void SetValueTranspose(const Matrix&);
		void SetValueTranspose(const std::vector<Matrix>&);

	private:
		GLint _id;
		i32 _colCount, _rowCount;
		std::string _name, _sem;
		EffectParameterCollection _elems;
		XNA::ParameterClass _pClass;
		XNA::ParameterType _pType;
		EffectParameterCollection _structMemb;
	};
}


#endif