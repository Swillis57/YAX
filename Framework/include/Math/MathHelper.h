#ifndef _MATH_HELPER_H
#define _MATH_HELPER_H

namespace YAX
{
	namespace MathHelper
	{
		static const float E;
		static const float Log10E;
		static const float Log2E;
		static const float Pi;
		static const float PiOver2;
		static const float PiOver4;
		static const float TwoPi;

		static float Barycentric(float p1, float p2, float p3, float p4, float w);
		static float CatmullRom(float p1, float p2, float p3, float p4, float t);
		static float Clamp(float val, float min, float max);
		static float Distance(float val1 , float val2);
		static float Hermite(float val1, float m1, float val2, float m2, float t);
		static float Lerp(float val1, float val2, float t);
		static float Max(float val1, float val2);
		static float Min(float val1, float val2);
		static float SmoothStep(float val1, float val2, float t);
		static float ToDegrees(float val);
		static float ToRadians(float val);
		static float WrapAngle(float val);
	};
}

#endif 