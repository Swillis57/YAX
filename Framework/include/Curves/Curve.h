#ifndef CURVE
#define CURVE

#include <vector>
#include <memory>
#include "../Utils.h"
#include "CurveKey.h"
#include "CurveLoopType.h"
#include "CurveTangent.h"

namespace XNA
{
	typedef std::vector<CurveKey> CurveKeyCollection;

	class Curve
	{
	public:
		Curve();

		bool IsConstant();
		CurveKeyCollection* Keys();
		CurveLoopType PostLoop();
		CurveLoopType PreLoop();

		void ComputeTangent(i32, CurveTangent);
		void ComputeTangent(i32, CurveTangent, CurveTangent);

		void ComputeTangents(CurveTangent);
		void ComputeTangents(CurveTangent, CurveTangent);

		float Evaluate(float);

	private:
		bool _isConst;
		std::unique_ptr<CurveKeyCollection> _keys;
		CurveLoopType _postLoop;
		CurveLoopType _preLoop;

	};
}


#endif