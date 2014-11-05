#ifndef _EFFECT_TECHNIQUE_H
#define _EFFECT_TECHNIQUE_H

#include <string>
#include "EffectAnnotationCollection.h"
#include "EffectPassCollection.h"


namespace XNA
{
	//An EffectTechnique represents a collection of passes
	class EffectTechnique
	{
	public:
		std::string Name();
		EffectPassCollection Passes();

	private:
		std::string _name;
		EffectPassCollection _passes;
	};
}


#endif