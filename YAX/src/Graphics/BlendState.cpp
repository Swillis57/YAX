#include "Graphics/BlendState.h"

#include "Graphics/Blend.h"
#include "Graphics/BlendFunction.h"
#include "Color.h"
#include "Graphics/ColorWriteChannels.h"

namespace YAX
{
    const BlendState BlendState::Additive = BlendState(
        "BlendState::Additive",
        Blend::SourceAlpha,
        Blend::SourceAlpha,
        Blend::One,
        Blend::One
    );

    const BlendState BlendState::AlphaBlend = BlendState(
        "BlendState::AlphaBlend",
        Blend::One,
        Blend::One,
        Blend::InverseSourceAlpha,
        Blend::InverseSourceAlpha
    );

    const BlendState BlendState::NonPremultiplied = BlendState(
        "BlendState::NonPremultiplied",
        Blend::SourceAlpha,
        Blend::SourceAlpha,
        Blend::InverseSourceAlpha,
        Blend::InverseSourceAlpha
    );

    const BlendState BlendState::Opaque = BlendState(
        "BlendState::Opaque",
        Blend::One,
        Blend::One,
        Blend::Zero,
        Blend::Zero
    );

    BlendState::BlendState(
        std::string name = "",
        Blend colorSourceBlend = Blend::One, 
        Blend colorDestBlend = Blend::Zero, 
        Blend alphaSourceBlend = Blend::One, 
        Blend alphaDestBlend = Blend::Zero
    )
        : _alphaBlendFunc(BlendFunction::Add),
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

    BlendFunction BlendState::AlphaBlendFunction() const
    {
        return _alphaBlendFunc;
    }

    void BlendState::AlphaBlendFunction(BlendFunction func)
    {
        _alphaBlendFunc = func;
    }

    Blend BlendState::AlphaDestinationBlend() const
    {
        return _alphaDestBlend;
    }

    void BlendState::AlphaDestinationBlend(Blend b)
    {
        _alphaDestBlend = b;
    }

    Blend BlendState::AlphaSourceBlend() const
    {
        return _alphaSrcBlend;
    }

    void BlendState::AlphaSourceBlend(Blend b)
    {
        _alphaSrcBlend = b;
    }

    Color BlendState::BlendFactor() const
    {
        return _blendFactor;
    }

    void BlendState::BlendFactor(const Color& c)
    {
        _blendFactor = c;
    }

    BlendFunction BlendState::ColorBlendFunction() const
    {
        return _colorBlendFunc;
    }

    void BlendState::ColorBlendFunction(BlendFunction func)
    {
        _colorBlendFunc = func;
    }

    Blend BlendState::ColorDestinationBlend() const
    {
        return _colorDestBlend;
    }

    void BlendState::ColorDestinationBlend(Blend b)
    {
        _colorDestBlend = b;
    }

    Blend BlendState::ColorSourceBlend() const
    {
        return _colorSrcBlend;
    }

    void BlendState::ColorSourceBlend(Blend b)
    {
        _colorSrcBlend = b;
    }

    ColorWriteChannels BlendState::ColorWriteChannels0() const
    {
        return _cwc0;
    }

    void BlendState::ColorWriteChannels0(ColorWriteChannels cwc)
    {
        _cwc0 = cwc;
    }

    ColorWriteChannels BlendState::ColorWriteChannels1() const
    {
        return _cwc1;
    }

    void BlendState::ColorWriteChannels1(ColorWriteChannels cwc)
    {
        _cwc1 = cwc;
    }
    ColorWriteChannels BlendState::ColorWriteChannels2() const
    {
        return _cwc2;
    }

    void BlendState::ColorWriteChannels2(ColorWriteChannels cwc)
    {
        _cwc2 = cwc;
    }
    ColorWriteChannels BlendState::ColorWriteChannels3() const
    {
        return _cwc3;
    }

    void BlendState::ColorWriteChannels3(ColorWriteChannels cwc)
    {
        _cwc3 = cwc;
    }

    i32 BlendState::MultiSampleMask() const
    {
        return _multiSampleMask;
    }

    void BlendState::MultiSampleMask(i32 ms)
    {
        _multiSampleMask = ms;
    }

    bool operator==(const BlendState& lhs, const BlendState& rhs)
    {
        return (lhs._alphaBlendFunc == rhs._alphaBlendFunc
            && lhs._colorBlendFunc == rhs._colorBlendFunc
            && lhs._alphaDestBlend == rhs._alphaDestBlend
            && lhs._alphaSrcBlend == rhs._alphaSrcBlend
            && lhs._colorDestBlend == rhs._colorDestBlend
            && lhs._colorSrcBlend == rhs._colorSrcBlend
            && lhs._blendFactor == rhs._blendFactor
            && lhs._cwc0 == rhs._cwc0
            && lhs._cwc1 == rhs._cwc1
            && lhs._cwc2 == rhs._cwc2
            && lhs._cwc3 == rhs._cwc3);
    }

    bool operator!=(const BlendState& lhs, const BlendState& rhs)
    {
        return !(lhs == rhs);
    }
}