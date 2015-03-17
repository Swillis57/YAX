#ifndef _CURVE_KEY_H
#define _CURVE_KEY_H

#include <memory>

namespace YAX
{
	enum class CurveContinuity : int;
	

	class CurveKey
	{			
		struct Impl;

	public:
		CurveKey(float, float);
		CurveKey(float, float, float, float);
		CurveKey(float, float, float, float, CurveContinuity);
		~CurveKey();


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
		std::unique_ptr<Impl> _impl;
	};
}


#endif