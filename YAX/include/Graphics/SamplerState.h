#ifndef _SAMPLER_STATE_H
#define _SAMPLER_STATE_H

#include "../Utils.h"

namespace YAX
{
	enum class TextureAddressMode : int;
	enum class TextureFilter : int;

	class SamplerState
	{
	public:
		SamplerState();

		static const SamplerState AnisotropicClamp; 
		static const SamplerState AnisotropicWrap;
		static const SamplerState LinearClamp;
		static const SamplerState LinearWrap;
		static const SamplerState PointClamp;
		static const SamplerState PointWrap;

		TextureAddressMode AddressU() const;
		void AddressU(TextureAddressMode);

		TextureAddressMode AddressV() const;
		void AddressV(TextureAddressMode);

		TextureAddressMode AddressW() const;
		void AddressW(TextureAddressMode);

		TextureFilter Filter() const;
		void Filter(TextureFilter);

		i32 MaxAnisotropy() const;
		void MaxAnisotropy(i32);

		i32 MaxMipLevel() const;
		void MaxMipLevel(i32);

		float MipMapLevelofDetailBias() const;
		void MipMapLevelofDetailBias(float);

	private:
		TextureAddressMode _u, _v, _w;
		TextureFilter _filter;
		i32 _maxAniso;
		i32 _maxMipLevel;
		float _mipLodBias;
	};
}


#endif