#ifndef _CURVE_LOOP_TYPE_H
#define _CURVE_LOOP_TYPE_H

namespace YAX
{
	enum class CurveLoopType : int 
	{
		Constant,
		Cycle,
		CycleOffset,
		Linear,
		Oscillate
	};
}


#endif