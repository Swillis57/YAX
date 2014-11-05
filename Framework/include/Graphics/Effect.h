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

	//Effect is a collection of shader programs
	class Effect : public GraphicsResource
	{
	public:
		Effect(const Effect&);
		Effect(XNA::GraphicsDevice&, const std::vector<byte>&);
	
		EffectTechnique CurrentTechnique() const;
		void CurrentTechnique(const EffectTechnique&);
		
		EffectParameterCollection Parameters() const;

		EffectTechniqueCollection Techniques() const;

	protected:
		EffectTechnique _currTechnique;
		EffectParameterCollection _params;
		EffectTechniqueCollection _techniques;
	};
}


#endif
