#ifndef _EFFECT_H
#define _EFFECT_H

#include <vector>
#include "GraphicsResource.h"
#include "EffectParameterCollection.h"
#include "EffectProgramCollection.h"
#include "EffectProgram.h"

namespace XNA
{
	typedef char byte;

	class GraphicsDevice;

	//An Effect represents a collection of shader techniques.
	class Effect : public GraphicsResource
	{
	public:
		Effect(XNA::GraphicsDevice&, const std::vector<byte>&);
		Effect(const Effect&) = default;
		Effect& operator=(const Effect&) = default;
	
		EffectProgram CurrentProgram() const;
		void CurrentProgram(const EffectProgram&);
		
		EffectParameterCollection Parameters() const;

		EffectProgramCollection Programs() const;

	protected:
		EffectProgram _currProgram;
		EffectParameterCollection _params;
		EffectProgramCollection _programs;
	};
}


#endif
