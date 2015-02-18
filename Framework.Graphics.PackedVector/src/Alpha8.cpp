#include "../include/Alpha8.h"
#include "../../Framework.Math/include/Vector4.h"

namespace YAX
{
	Alpha8::Alpha8(float val)
		: Alpha8::Base()
	{
	
		_packed = val * 255;
	}

	Alpha8::~Alpha8() = default;

	float Alpha8::ToAlpha() const
	{
		return _packed / 255.0f;
	}

	void Alpha8::PackFromVector4(const Vector4& vec)
	{
		_packed = vec.W * 255;
	}

	Vector4 Alpha8::ToVector4() const
	{
		return Vector4(0.0f, 0.0f, 0.0f, ToAlpha());
	}

	bool operator==(const Alpha8& lhs, const Alpha8& rhs)
	{
		return lhs._packed == rhs._packed;
	}

	bool operator!=(const Alpha8& lhs, const Alpha8& rhs)
	{
		return !(lhs == rhs);
	}
}