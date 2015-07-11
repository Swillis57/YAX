#ifndef _DIRECTIONAL_LIGHT_H
#define _DIRECTIONAL_LIGHT_H

#include "../Vector3.h"
#include "EffectParameter.h"

namespace YAX
{
	class DirectionalLight
	{

	public:
		DirectionalLight(const EffectParameter& dir, const EffectParameter& diffuse, const EffectParameter& specular);
		DirectionalLight(const DirectionalLight&);

		Vector3 DiffuseColor() const;
		void DiffuseColor(const Vector3&);

		Vector3 Direction() const;
		void Direction(const Vector3&);

		Vector3 SpecularColor() const;
		void SpecularColor(const Vector3&);

		bool Enabled() const;
		void Enabled(bool);

	private:
		Vector3 _diffColor, _specColor, _dir;
		EffectParameter _diffParam, _specParam, _dirParam;
		bool _enabled;
	};
}


#endif