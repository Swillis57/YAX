#ifndef _CURVE_H
#define _CURVE_H

#include <memory>
#include "CurveKeyCollection.h"
#include "Utils.h"

namespace YAX
{
	enum class CurveLoopType : int;
	enum class CurveTangent : int;

	class Curve
	{
		struct Impl;

	public:
		Curve();
		~Curve();

		bool IsConstant() const;
		CurveKeyCollection& Keys() const;
		CurveLoopType PostLoop() const;
		CurveLoopType PreLoop() const;

		void ComputeTangent(i32, CurveTangent);
		void ComputeTangent(i32, CurveTangent, CurveTangent);

		void ComputeTangents(CurveTangent);
		void ComputeTangents(CurveTangent, CurveTangent);

		float Evaluate(float) const;

	private:
		std::unique_ptr<Impl> _impl;

	};
}


#endif