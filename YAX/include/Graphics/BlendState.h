#ifndef _BLEND_STATE_H
#define _BLEND_STATE_H

#include <string>
#include "GraphicsResource.h"
#include "../Color.h"
#include "../Utils.h"

namespace YAX
{
	enum class Blend : int;
	enum class BlendFunction : int;
	enum class ColorWriteChannels : int;

	class BlendState : public GraphicsResource
	{
	public:
		static const BlendState Additive;
		static const BlendState AlphaBlend;
		static const BlendState NonPremultiplied;
		static const BlendState Opaque;

		BlendState(std::string, Blend, Blend, Blend, Blend);
		~BlendState() = default;
		
		BlendFunction AlphaBlendFunction();
		void AlphaBlendFunction(BlendFunction);

		Blend AlphaDestinationBlend();
		void AlphaDestinationBlend(Blend);

		Blend AlphaSourceBlend();
		void AlphaSourceBlend(Blend);

		Color BlendFactor();
		void BlendFactor(const Color&);

		BlendFunction ColorBlendFunction();
		void ColorBlendFunction(BlendFunction);

		Blend ColorDestinationBlend();
		void ColorDestinationBlend(Blend);

		Blend ColorSourceBlend();
		void ColorSourceBlend(Blend);

		ColorWriteChannels ColorWriteChannels0();
		void ColorWriteChannels0(ColorWriteChannels); 

		ColorWriteChannels ColorWriteChannels1();
		void ColorWriteChannels1(ColorWriteChannels);

		ColorWriteChannels ColorWriteChannels2();
		void ColorWriteChannels2(ColorWriteChannels);

		ColorWriteChannels ColorWriteChannels3();
		void ColorWriteChannels3(ColorWriteChannels);

		i32 MultiSampleMask();
		void MultiSampleMask(i32);

	private:
		BlendFunction _alphaBlendFunc, _colorBlendFunc;
		Blend _alphaDestBlend, _alphaSrcBlend, _colorDestBlend, _colorSrcBlend;
		Color _blendFactor;
		ColorWriteChannels _cwc0, _cwc1, _cwc2, _cwc3;
		i32 _multiSampleMask;

	};
}


#endif