#ifndef _EFFECT_TECHNIQUE_H
#define _EFFECT_TECHNIQUE_H

#include <string>
#include "EffectAnnotationCollection.h"
#include "EffectPassCollection.h"


namespace XNA
{
	class EffectTechnique
	{
	public:
		EffectAnnotationCollection Annotations();
		std::string Name();
		EffectPassCollection Passes();

	private:
		EffectAnnotationCollection _annotations;
		std::string _name;
		EffectPassCollection _passes;
	};
}


#endif