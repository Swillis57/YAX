#ifndef _CURVE_KEY_H
#define _CURVE_KEY_H


namespace XNA
{
	enum class CurveContinuity : int;

	class CurveKey
	{
	public:
		CurveKey(float, float);
		CurveKey(float, float, float, float);
		CurveKey(float, float, float, float, CurveContinuity);

		float Position() const;

		float TangentIn() const;
		void TangentIn(float);

		float TangentOut() const;
		void TangentOut(float);

		float Value() const;
		void Value(float);

		CurveContinuity Continuity() const;
		void Continuity(CurveContinuity);

		friend bool operator==(const CurveKey&, const CurveKey&);
		friend bool operator!=(const CurveKey&, const CurveKey&);

	private:
		float _pos, _tanIn, _tanOut, _val;
		CurveContinuity _continuity;
	};
}


#endif