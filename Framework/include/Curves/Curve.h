#ifndef _CURVE_H
#define _CURVE_H

#include "CurveKeyCollection.h"
#include "../Utils.h"

namespace XNA
{
	enum class CurveLoopType : int;
	enum class CurveTangent : int;

	class Curve
	{
	public:
		Curve();

		bool IsConstant() const;
		CurveKeyCollection Keys() const;
		CurveLoopType PostLoop() const;
		CurveLoopType PreLoop() const;

		void ComputeTangent(i32, CurveTangent);
		void ComputeTangent(i32, CurveTangent, CurveTangent);

		void ComputeTangents(CurveTangent);
		void ComputeTangents(CurveTangent, CurveTangent);

		float Evaluate(float) const;

	private:
		bool _isConst;
		CurveKeyCollection _keys;
		CurveLoopType _postLoop, _preLoop;

	};
}


#endif