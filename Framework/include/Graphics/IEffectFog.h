#ifndef _I_EFFECT_FOG_H
#define _I_EFFECT_FOG_H

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