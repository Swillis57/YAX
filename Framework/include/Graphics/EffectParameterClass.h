#ifndef _EFFECT_PARAMETER_CLASS_H
#define _EFFECT_PARAMETER_CLASS_H

#include <vector>

namespace XNA
{

	enum class EffectParameterClass : int 
	{
		Matrix,
		Object,
		Scalar,
		Struct,
		Vector
	};
}


#endif