#ifndef _I_EFFECT_FOG_H
#define _I_EFFECT_FOG_H

#include "../Math/Vector3.h"

namespace YAX
{
	class IEffectFog
	{
	public:
		virtual ~IEffectFog() = 0;

		Vector3 FogColor() const;
		void FogColor(const Vector3&);

		bool FogEnabled() const;
		void FogEnabled(bool);

		float FogStart() const;
		void FogStart(float);

		float FogEnd() const;
		void FogEnd(float);

	protected:
		Vector3 _fogColor;
		bool _fogEnabled;
		float _fogEnd, _fogStart;
	};
}


#endif