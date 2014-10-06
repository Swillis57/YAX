#ifndef _CURVE_KEY_H
#define _CURVE_KEY_H


namespace XNA
{
	enum CurveContinuity : short;

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