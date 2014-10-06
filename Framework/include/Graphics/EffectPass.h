#ifndef _EFFECT_PASS_H
#define _EFFECT_PASS_H

#include <string>
#include "EffectAnnotationCollection.h"

namespace XNA
{
	class EffectPass
	{
	public:
		EffectAnnotationCollection Annotations();
		std::string Name();
		
		void Apply();

	private:
		EffectAnnotationCollection _annotations;
		std::string _name;
	};

}


#endif