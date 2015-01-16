#include "../../include/Math/MathHelper.h"
#define _USE_MATH_DEFINES
#include <cmath>

namespace YAX
{
	const float MathHelper::E = M_E;
	const float MathHelper::Log10E = M_LOG10E;
	const float MathHelper::Log2E = M_LOG2E;
	const float MathHelper::Pi = M_PI;
	const float MathHelper::PiOver2 = M_PI_2;
	const float MathHelper::PiOver4 = M_PI_4;
	const float MathHelper::TwoPi = 2 * Pi;

	float MathHelper::Barycentric(float vert1, float vert2, float vert3, float weight2, float weight3)
	{
		return ((1 - weight2 - weight3) * vert1 + weight2 * vert2 + weight3 * vert3);
	}
}