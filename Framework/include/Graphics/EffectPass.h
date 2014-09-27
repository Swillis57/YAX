#ifndef EFFECT_PASS
#define EFFECT_PASS

#include <string>
#include "EffectAnnotation.h"

namespace XNA
{
	class EffectPass
	{
	public:
		EffectAnnotationCollection Annotations();
		std::string Name();
		
		void Apply();
	};
}


#endif