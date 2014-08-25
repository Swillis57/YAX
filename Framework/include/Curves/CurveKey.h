#ifndef CURVE_KEY
#define CURVE_KEY


namespace XNA
{
	enum CurveContinuity;

	class CurveKey
	{
	public:
		CurveContinuity Continuity;
		float TangentIn, TangentOut, Value;

		CurveKey(float, float);
		CurveKey(float, float, float, float);
		CurveKey(float, float, float, float, CurveContinuity);

		float Position();

		bool operator==(const CurveKey&);
		bool operator!=(const CurveKey&);

	private:
		float _pos;
	};
}


#endif