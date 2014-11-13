#ifndef _EFFECT_H
#define _EFFECT_H

#include <vector>
#include "GraphicsResource.h"
#include "EffectParameterCollection.h"
#include "EffectProgramCollection.h"
#include "EffectProgram.h"

namespace YAX
{
	typedef char byte;

	class GraphicsDevice;

	//An Effect represents a collection of shader techniques.
	class Effect : public GraphicsResource
	{
	public:
		Effect(YAX::GraphicsDevice&, const std::vector<byte>&);
		Effect(const Effect&) = delete;
		Effect& operator=(const Effect&) = delete;
		Effect(Effect&&);
		Effect& operator=(Effect&&);
		~Effect();
	
		EffectProgram CurrentProgram() const;
		void CurrentProgram(const EffectProgram&);
		
		EffectParameterCollection Parameters() const;

		EffectProgramCollection Programs() const;

	protected:
		EffectProgram&_currProgram;
		EffectParameterCollection _params;
		EffectProgramCollection _programs;
	};
}


#endif
