#ifndef _MATH_HELPER_H
#define _MATH_HELPER_H

namespace YAX
{
	struct MathHelper
	{
		static const float E;
		static const float Log10E;
		static const float Log2E;
		static const float Pi;
		static const float PiOver2;
		static const float PiOver4;
		static const float TwoPi;

		static float Barycentric(float, float, float, float, float);
		static float CatmullRom(float, float, float, float, float);
		static float Clamp(float, float, float);
		static float Distance(float, float);
		static float Hermite(float, float, float, float, float);
		static float Lerp(float, float, float);
		static float Max(float, float);
		static float Min(float, float);
		static float SmoothStep(float, float, float);
		static float ToDegrees(float);
		static float ToRadians(float);
		static float WrapAngle(float);
	};
}

#endif 