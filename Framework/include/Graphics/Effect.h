#ifndef _EFFECT_H
#define _EFFECT_H

#include <vector>
#include "GraphicsResource.h"
#include "EffectParameterCollection.h"
#include "EffectTechniqueCollection.h"
#include "EffectTechnique.h"

namespace XNA
{
	typedef char byte;

	class GraphicsDevice;


	class Effect : GraphicsResource
	{
	public:
		Effect(const Effect&);
		Effect(const XNA::GraphicsDevice&, std::vector<byte>);
	
		EffectTechnique CurrentTechnique();
		void CurrentTechnique(const EffectTechnique&);
		
		EffectParameterCollection Parameters();

		EffectTechniqueCollection Techniques();

	private:
		EffectTechnique _currTechnique;
		EffectParameterCollection _params;
		EffectTechniqueCollection _techniques;
	};
}


#endif
