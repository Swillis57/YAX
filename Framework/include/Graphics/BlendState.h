#ifndef _BLEND_STATE_H
#define _BLEND_STATE_H

#include "GraphicsResource.h"
#include "../Color.h"

namespace XNA
{
	enum class Blend;
	enum class BlendFunction;
	enum class ColorWriteChannels;

	class BlendState : public GraphicsResource
	{
	public:
		BlendState();
		~BlendState();
		
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

		XNA::ColorWriteChannels ColorWriteChannels0();
		void ColorWriteChannels0(XNA::ColorWriteChannels); 

		XNA::ColorWriteChannels ColorWriteChannels1();
		void ColorWriteChannels1(XNA::ColorWriteChannels);

		XNA::ColorWriteChannels ColorWriteChannels2();
		void ColorWriteChannels2(XNA::ColorWriteChannels);

		XNA::ColorWriteChannels ColorWriteChannels3();
		void ColorWriteChannels3(XNA::ColorWriteChannels);

		i32 MultiSampleMask();
		void MultiSampleMask(i32);

		static const BlendState Additive;
		static const BlendState AlphaBlend;
		static const BlendState NonPremultiplied;
		static const BlendState Opaque;

	private:
		BlendFunction _alphaBlendFunc;
		Blend _alphaDestBlend;
		Blend _alphaSrcBlend;
		Color _blendFactor;
		BlendFunction _colorBlendFunc;
		Blend _colorDestBlend;
		Blend _colorSrcBlend;
		XNA::ColorWriteChannels _crc0;
		XNA::ColorWriteChannels _crc1;
		XNA::ColorWriteChannels _crc2;
		XNA::ColorWriteChannels _crc3;
		i32 _multiSampleMask;

	};
}


#endif