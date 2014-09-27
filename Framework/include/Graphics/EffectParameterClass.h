#ifndef EFFECT_PARAMETER_CLASS
#define EFFECT_PARAMETER_CLASS

#include <vector>

namespace XNA
{
	typedef std::vector<EffectParameterClass> EffectParameterCollection;

	enum EffectParameterClass : short
	{
		Matrix,
		Object,
		Scalar,
		Struct,
		Vector
	};
}


#endif