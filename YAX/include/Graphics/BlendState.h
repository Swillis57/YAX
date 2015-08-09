#ifndef _BLEND_STATE_H
#define _BLEND_STATE_H

#include <string>
#include "../Color.h"
#include "../Utils.h"

namespace YAX
{
    enum class Blend : ui32;
    enum class BlendFunction : ui32;
    enum class ColorWriteChannels : ui32;

    class BlendState
    {
    public:
        friend class GraphicsDevice;

        static const BlendState Additive;
        static const BlendState AlphaBlend;
        static const BlendState NonPremultiplied;
        static const BlendState Opaque;

        BlendState(std::string, Blend, Blend, Blend, Blend);
        BlendState(const BlendState&) = default;
        ~BlendState() = default;
        
        BlendFunction AlphaBlendFunction() const;
        void AlphaBlendFunction(BlendFunction);

        Blend AlphaDestinationBlend() const;
        void AlphaDestinationBlend(Blend);

        Blend AlphaSourceBlend() const;
        void AlphaSourceBlend(Blend);

        Color BlendFactor() const;
        void BlendFactor(const Color&);

        BlendFunction ColorBlendFunction() const;
        void ColorBlendFunction(BlendFunction);

        Blend ColorDestinationBlend() const;
        void ColorDestinationBlend(Blend);

        Blend ColorSourceBlend() const;
        void ColorSourceBlend(Blend);

        ColorWriteChannels ColorWriteChannels0() const;
        void ColorWriteChannels0(ColorWriteChannels); 

        ColorWriteChannels ColorWriteChannels1() const;
        void ColorWriteChannels1(ColorWriteChannels);

        ColorWriteChannels ColorWriteChannels2() const;
        void ColorWriteChannels2(ColorWriteChannels);

        ColorWriteChannels ColorWriteChannels3() const;
        void ColorWriteChannels3(ColorWriteChannels);

        i32 MultiSampleMask() const;
        void MultiSampleMask(i32);

        friend bool operator==(const BlendState&, const BlendState&);
        friend bool operator!=(const BlendState&, const BlendState&);

    private:
        BlendFunction _alphaBlendFunc, _colorBlendFunc;
        Blend _alphaDestBlend, _alphaSrcBlend, _colorDestBlend, _colorSrcBlend;
        Color _blendFactor;
        ColorWriteChannels _cwc0, _cwc1, _cwc2, _cwc3;
        i32 _multiSampleMask;

    };
}


#endif