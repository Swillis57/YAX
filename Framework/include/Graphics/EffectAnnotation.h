#ifndef EFFECT_ANNOTATION
#define EFFECT_ANNOTATION

#include <string>
#include <vector>
#include "../Utils.h"

namespace XNA
{
	typedef std::vector<EffectAnnotation> EffectAnnotationCollection;

	enum EffectParameterClass : short;
	enum EffectParameterType : short;

	class Matrix;
	class Vector2;
	class Vector3;
	class Vector4;

	class EffectAnnotation
	{
	public:
		i32 ColumnCount();
		std::string Name();
		EffectParameterClass ParameterClass();
		EffectParameterType ParameterType();
		i32 RowCount();
		std::string Semantic();

		bool GetValueBoolean();
		i32 GetValueInt32();
		Matrix GetValueMatrix();
		float GetValueSingle();
		std::string GetValueString();
		Vector2 GetValueVector2();
		Vector3 GetValueVector3();
		Vector4 GetValueVector4();


	private:
		i32 _colCount, _rowCount;
		std::string _name, _semantic;
		EffectParameterClass _paramClass;
		EffectParameterType _paramType;
	};
}


#endif