#ifndef I_EFFECT_FOG
#define I_EFFECT_FOG

#include "../Math/Vector3.h"

namespace XNA
{
	class IEffectFog
	{
	public:
		virtual ~IEffectFog();

		Vector3 FogColor;
		bool FogEnabled;
		float FogEnd, FogStart;
	};
}


#endif