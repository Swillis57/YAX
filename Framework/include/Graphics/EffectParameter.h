#ifndef _EFFECT_PARAMETER_H
#define _EFFECT_PARAMETER_H

#include <string>
#include "EffectParameterCollection.h"
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

	typedef bool Boolean;
	typedef float Single;

	//EffectParameter is equivalent to a uniform in OpenGL
	class EffectParameter
	{
	public:
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
		void SetValueTranspost(std::vector<Matrix>);

	private:
		i32 _colCount, _rowCount;
		std::string _name, _sem;
		EffectParameterCollection _elems;
		XNA::ParameterClass _pClass;
		XNA::ParameterType _pType;
		EffectParameterCollection _structMemb;
		
	};
}


#endif