#ifndef EFFECT_TECHNIQUE
#define EFFECT_TECHNIQUE

#include <string>
#include "EffectAnnotation.h"


namespace XNA
{
	class EffectTechnique
	{
	public:
		EffectAnnotationCollection Annotations();
		std::string Name;

	};
}


#endif