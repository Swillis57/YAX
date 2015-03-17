#define _USE_MATH_DEFINES
#include <cmath>
#include "../include/MathHelper.h"

namespace YAX
{
	const float MathHelper::E = static_cast<float>(M_E);
	const float MathHelper::Log10E = static_cast<float>(M_LOG10E);
	const float MathHelper::Log2E = static_cast<float>(M_LOG2E);
	const float MathHelper::Pi = static_cast<float>(M_PI);
	const float MathHelper::PiOver2 = static_cast<float>(M_PI_2);
	const float MathHelper::PiOver4 = static_cast<float>(M_PI_4);
	const float MathHelper::TwoPi = 2 * MathHelper::Pi;

	float MathHelper::Barycentric(float vert1, float vert2, float vert3, float weight2, float weight3)
	{
		weight2 = Clamp(weight2, 0, 1);
		weight3 = Clamp(weight3, 0, 1);

		return ((1 - weight2 - weight3) * vert1 + weight2 * vert2 + weight3 * vert3);
	}

	float MathHelper::CatmullRom(float p1, float p2, float p3, float p4, float t)
	{
		//using simplified basis matrix from http://www.cs.cmu.edu/~462/projects/assn2/assn2/catmullRom.pdf
		float threeHalves = 1.5f*t, oneHalf = t / 2.0f;
		
		float c1 = (-0.5f + t*(1 - oneHalf))*p1;
		float c2 = (1 + (t*t*(-2.5f + threeHalves)))*p2;
		float c3 = (0.5f + t*(2 - threeHalves))*p3;
		float c4 = (-0.5f + oneHalf)*t*p4;

		return c2 + t*(c1 + c3 + c4);
	}

	float MathHelper::Clamp(float val, float min, float max)
	{
		return Max(min, Min(max, val));
	}

	float MathHelper::Distance(float val1, float val2)
	{
		return std::abs(val1 - val2);
	}

	float MathHelper::Hermite(float val1, float m1, float val2, float m2, float t)
	{
		float c1 = std::pow(1 - t, 2)*((1 + 2*t)*val1 + t*m1);
		float c2 = t*t*((3 - 2*t)*val2 + (t - 1)*m2);

		return c1 + c2;
	}

	float MathHelper::Lerp(float val1, float val2, float t)
	{
		return val1 + (val2 - val1) * t;
	}

	float MathHelper::Max(float val1, float val2)
	{
		return (val1 > val2 ? val1 : val2);
	}

	float MathHelper::Min(float val1, float val2)
	{
		return (val1 < val2 ? val1 : val2);
	}

	float MathHelper::SmoothStep(float val1, float val2, float t)
	{
		t = Clamp(t, 0, 1);
		return Lerp(val1, val2, t*t*(3 - 2 * t));
	}

	i32 MathHelper::Sign(float v)
	{
		return (v > 0 ? 1 : (v == 0 ? 0 : -1));
	}

	float MathHelper::ToDegrees(float val)
	{
		return val*180.0f / Pi;
	}

	float MathHelper::ToRadians(float val)
	{
		return val*Pi / 180.0f;
	}

	float MathHelper::WrapAngle(float val)
	{
		val = std::fmodf(val, TwoPi);;
		return (val > Pi ? -(TwoPi - val) : val);
	}

}