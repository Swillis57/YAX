#ifndef _MATH_HELPER_H
#define _MATH_HELPER_H

#include "../../YAX/include/Utils.h"

namespace YAX
{
	namespace MathHelper
	{
		extern const float E;
		extern const float Log10E;
		extern const float Log2E;
		extern const float Pi;
		extern const float PiOver2;
		extern const float PiOver4;
		extern const float TwoPi;

		/**
		* @brief Calculates a coordinate of a point defined by a triangle and two barycentric coordinates.
		*
		* @param p1, p2, p3 Coordinates of the points defining the triangle on a given axis
		* @param b2, b3 The barycentric coordinates
		* @return The interpolated coordinate on the same axis as p1, p2, and p3										   
		*/
		float Barycentric(float p1, float p2, float p3, float b2, float b3);
		
		/**
		* @brief Interpolates between given positions using Catmull-Rom interpolation
		* 
		* @param p1, p2, p3, p4 Coordinates of the points used in the interpolation on a given axis
		* @param t Interpolation factor
		* @return The interpolated coordinate on the same axis as p1, p2, p3, and p4
		*/
		float CatmullRom(float p1, float p2, float p3, float p4, float t);
		
		/**
		* @brief Clamps a given value to a given range
		*
		* @param val The value to clamp
		* @param min Lower bound
		* @param max Upper bound
		* @return The clamped value
		*/
		float Clamp(float val, float min, float max);

		/**
		* @brief Finds the absolute distance between two values
		*
		* @param val1 The first value
		* @param val2 The second value
		* @return The absolute difference between val1 and val2
		*/
		float Distance(float val1 , float val2);

		/**
		* @brief Interpolates between two values using a Hermite spline interpolation
		*
		* @param val1, val2 The values to interpolate between
		* @param m1, m2 Tangent values for respective points
		* @return The interpolated value between val1 and val2
		*/
		float Hermite(float val1, float m1, float val2, float m2, float t);
		
		/**
		* @brief Performs a linear interpolation between two values
		*
		* @param val1 The lower end of the range to interpolate
		* @param val2 The upper end of the range to interpolate
		* @param t Interpolation factor
		* @return The interpolated value between val1 and val2
		*/
		float Lerp(float val1, float val2, float t);
		
		/**
		* @brief Finds the maximum of two given values
		*
		* @param val1 The first value
		* @param val2 The second value
		* @return The largest of the two values
		*/
		float Max(float val1, float val2);

		/**
		* @brief Finds the minimum of two given values
		*
		* @param val1 The first value
		* @param val2 The second value
		* @return the lowest of the two values
		*/
		float Min(float val1, float val2);

		/**
		* @brief Performs a smoothstep interpolation between two given values
		*
		* @param val1 The initial valute
		* @param val2 The end value
		* @param t Interpolation factor
		* @return The interpolated value between val1 and val2
		*/
		float SmoothStep(float val1, float val2, float t);

		/**
		* @brief Extracts the sign of a provided number
		*
		* @param val The value to extract the sign from
		* @return -1 if val is negative, 1 if positive, 0 if 0
		*/
		i32 Sign(float v);

		/**
		* @brief Converts a given value to degrees
		*
		* @param val The value in radians to convert to degrees
		* @return The given value in degrees
		*/
		float ToDegrees(float val);

		/**
		* @brief Converts a given value to radians
		*
		* @param val The value in degrees to convert to radians
		* @return The given value in radians
		*/
		float ToRadians(float val);

		/**
		* @brief Wraps an angle in radians from [0, 2pi] to [0, +-pi]
		*
		* @param val The angle in radians to wrap
		* @return The wrapped angle
		*/
		float WrapAngle(float val);
	};
}

#endif 