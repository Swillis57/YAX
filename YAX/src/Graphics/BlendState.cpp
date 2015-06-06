#include "../../include/Graphics/BlendState.h"

#include "../../include/Graphics/Blend.h"
#include "../../include/Graphics/BlendFunction.h"
#include "../../include/Color.h"
#include "../../include/Graphics/ColorWriteChannels.h"
#include "../../include/Graphics/GraphicsResource.h"

namespace YAX
{
	BlendState::BlendState(
		std::string name = "",
		Blend colorSourceBlend = Blend::One, 
		Blend colorDestBlend = Blend::Zero, 
		Blend alphaSourceBlend = Blend::One, 
		Blend alphaDestBlend = Blend::Zero
	)
		: GraphicsResource(name),
		_alphaBlendFunc(BlendFunction::Add),
		_colorBlendFunc(BlendFunction::Add),
		_colorSrcBlend(colorSourceBlend),
		_colorDestBlend(colorDestBlend),
		_alphaSrcBlend(alphaSourceBlend),
		_alphaDestBlend(alphaDestBlend),
		_blendFactor(Color::White),
		_cwc0(ColorWriteChannels::All),
		_cwc1(ColorWriteChannels::All),
		_cwc2(ColorWriteChannels::All),
		_cwc3(ColorWriteChannels::All),
		_multiSampleMask(-1)
	{}

	BlendFunction BlendState::AlphaBlendFunction()
	{
		return _alphaBlendFunc;
	}

	void BlendState::AlphaBlendFunction(BlendFunction func)
	{
		_alphaBlendFunc = func;
	}

	Blend BlendState::AlphaDestinationBlend()
	{
		return _alphaDestBlend;
	}

	void BlendState::AlphaDestinationBlend(Blend b)
	{
		_alphaDestBlend = b;
	}

	Blend BlendState::AlphaSourceBlend()
	{
		return _alphaSrcBlend;
	}

	void BlendState::AlphaSourceBlend(Blend b)
	{
		_alphaSrcBlend = b;
	}

	Color BlendState::BlendFactor()
	{
		return _blendFactor;
	}

	void BlendState::BlendFactor(const Color& c)
	{
		_blendFactor = c;
	}

	BlendFunction BlendState::ColorBlendFunction()
	{
		return _colorBlendFunc;
	}

	void BlendState::ColorBlendFunction(BlendFunction func)
	{
		_colorBlendFunc = func;
	}

	Blend BlendState::ColorDestinationBlend()
	{
		return _colorDestBlend;
	}

	void BlendState::ColorDestinationBlend(Blend b)
	{
		_colorDestBlend = b;
	}

	Blend BlendState::ColorSourceBlend()
	{
		return _colorSrcBlend;
	}

	void BlendState::ColorSourceBlend(Blend b)
	{
		_colorSrcBlend = b;
	}

	ColorWriteChannels BlendState::ColorWriteChannels0()
	{
		return _cwc0;
	}

	void BlendState::ColorWriteChannels0(ColorWriteChannels cwc)
	{
		_cwc0 = cwc;
	}

	ColorWriteChannels BlendState::ColorWriteChannels1()
	{
		return _cwc1;
	}

	void BlendState::ColorWriteChannels1(ColorWriteChannels cwc)
	{
		_cwc1 = cwc;
	}
	ColorWriteChannels BlendState::ColorWriteChannels2()
	{
		return _cwc2;
	}

	void BlendState::ColorWriteChannels2(ColorWriteChannels cwc)
	{
		_cwc2 = cwc;
	}
	ColorWriteChannels BlendState::ColorWriteChannels3()
	{
		return _cwc3;
	}

	void BlendState::ColorWriteChannels3(ColorWriteChannels cwc)
	{
		_cwc3 = cwc;
	}

	i32 BlendState::MultiSampleMask()
	{
		return _multiSampleMask;
	}

	void BlendState::MultiSampleMask(i32 ms)
	{
		_multiSampleMask = ms;
	}
}