#ifndef SAMPLER_STATE
#define SAMPLER_STATE

#include "GraphicsResource.h"
#include "../Utils.h"

namespace XNA
{
	enum TextureAddressMode : short; 
	enum TextureFilter : short;

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

		TextureAddressMode AddressU();
		void AddressU(TextureAddressMode);

		TextureAddressMode AddressV();
		void AddressV(TextureAddressMode);

		TextureAddressMode AddressW();
		void AddressW(TextureAddressMode);

		TextureFilter Filter();
		void Filter(TextureFilter);

		i32 MaxAnisotropy();
		void MaxAnisotropy(i32);

		i32 MaxMipLevel();
		void MaxMipLevel(i32);

		float MipMapLevelofDetailBias();
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