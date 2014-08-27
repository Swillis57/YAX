#ifndef CURVE
#define CURVE

#include <vector>
#include "../Utils.h"

namespace XNA
{
	class CurveKey;
	enum CurveLoopType : short;
	enum CurveTangent : short;


	typedef std::vector<CurveKey> CurveKeyCollection;

	class Curve
	{
	public:
		Curve();

		bool IsConstant();
		CurveKeyCollection Keys();
		CurveLoopType PostLoop();
		CurveLoopType PreLoop();

		void ComputeTangent(i32, CurveTangent);
		void ComputeTangent(i32, CurveTangent, CurveTangent);

		void ComputeTangents(CurveTangent);
		void ComputeTangents(CurveTangent, CurveTangent);

		float Evaluate(float);

	private:
		bool _isConst;
		CurveKeyCollection _keys;
		CurveLoopType _postLoop;
		CurveLoopType _preLoop;

	};
}


#endif