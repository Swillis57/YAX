#include "../../include/Curves/Curve.h"
#include "../../include/Curves/CurveLoopType.h"
#include "../../include/Curves/CurveTangent.h"
#include "../../include/Curves/CurveLoopType.h"

namespace YAX
{
	struct Curve::Impl
	{
		bool _isConst;
		CurveKeyCollection _keys;
		CurveLoopType _postLoop, _preLoop;

		void ComputeTangent(i32 idx, CurveTangent tangent)
		{
			ComputeTangent(idx, tangent, tangent);
		}

		void ComputeTangent(i32 idx, CurveTangent tangentIn, CurveTangent tangentOut)
		{
			if (_keys.size() == 1)
			{
				_keys[idx].TangentIn(0.0f);
				_keys[idx].TangentOut(0.0f);
				return;
			}

			_keys[idx].TangentIn(CalcInTangent(idx, tangentIn));
			_keys[idx].TangentOut(CalcOutTangent(idx, tangentOut));
		}

		void ComputeTangents(CurveTangent tangent)
		{
			for (size_t i = 0; i < _keys.size(); i++)
			{
				ComputeTangent(i, tangent);
			}
		}

		void ComputeTangents(CurveTangent tangentIn, CurveTangent tangentOut)
		{
			for (size_t i = 0; i < _keys.size(); i++)
			{
				ComputeTangent(i, tangentIn, tangentOut);
			}
		}

		float Evaluate(float pos) const
		{
			float res;
			switch (_preLoop)
			{

			}
		}

	private:
		float CalcInTangent(int idx, CurveTangent tangent)
		{

			switch (tangent)
			{
				case CurveTangent::Flat:
					return 0.0f;

				case CurveTangent::Linear:
					return idx == 0 ? 0.0f : _keys[idx].Value() - _keys[idx - 1].Value();

				case CurveTangent::Smooth:
					int next = idx + 1, prev = idx - 1;
					if (idx == 0) prev = 0;
					if (idx == _keys.size() - 1) next = idx;

					return (_keys[next].Value() - _keys[prev].Value())
						* (_keys[idx].Position() - _keys[prev].Position())
						/ (_keys[next].Position() - _keys[prev].Position());
			}
		}

		float CalcOutTangent(int idx, CurveTangent tangent)
		{
			switch (tangent)
			{
				case CurveTangent::Flat:
					return 0.0f;

				case CurveTangent::Linear:
					return idx == 0 ? 0.0f : _keys[idx + 1].Value() - _keys[idx].Value();

				case CurveTangent::Smooth:
					int next = idx + 1, prev = idx - 1;
					if (idx == 0) prev = 0;
					if (idx == _keys.size() - 1) next = idx;

					return (_keys[next].Value() - _keys[prev].Value())
						* (_keys[next].Position() - _keys[idx].Position())
						/ (_keys[next].Position() - _keys[prev].Position());
			}
		}
	};
}