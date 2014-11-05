#ifndef _EFFECT_PASS_H
#define _EFFECT_PASS_H

#include <string>
#include "EffectAnnotationCollection.h"

namespace XNA
{
	//An EffectPass represents a single shader program
	class EffectPass
	{
	public:
		std::string Name();
		
		void Apply();

	private:
		std::string _name;
	};

}


#endif