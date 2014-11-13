#ifndef _MATH_HELPER_H
#define _MATH_HELPER_H

#include <cmath>
#include <numeric>
#include "../Utils.h"

namespace YAX
{
	namespace MathHelper
	{
		static const float E = std::exp(1);
		static const float Log10E = std::log10(E);
		static const float Log2E = std::log2(E);
		static const float Pi = M_PI;
		static const float PiOver2 = M_PI_2;
		static const float PiOver4 = M_PI_4;
		static const float TwoPi = 2 * Pi;

		float Barycentric(float, float, float, float, float);
		float CatmullRom(float, float, float, float, float);
		float Clamp(float, float, float);
		float Distance(float, float);
		float Hermite(float, float, float, float, float);
		float Lerp(float, float, float);
		float Max(float, float);
		float Min(float, float);
		float SmoothStep(float, float, float);
		float ToDegrees(float);
		float ToRadians(float);
		float WrapAngle(float);
	}
}

#endif 