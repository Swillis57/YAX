#ifndef _DIRECTIONAL_LIGHT_H
#define _DIRECTIONAL_LIGHT_H

#include "../Math/Vector3.h"

namespace XNA
{
	class EffectParameter;

	class DirectionalLight
	{
	public:
		DirectionalLight(const EffectParameter&, const EffectParameter&, const EffectParameter&);
		DirectionalLight(const DirectionalLight&);

		Vector3 DiffuseColor() const;
		void DiffuseColor(const Vector3&);

		Vector3 Direction() const;;
		void Direction(const Vector3&);

		Vector3 SpecularColor() const;;
		void SpecularColor(const Vector3&);

		bool Enabled() const;;
		void Enabled(bool);

	private:
		Vector3 _diffColor, _specColor, _dir;
		bool _enabled;
	};
}


#endif