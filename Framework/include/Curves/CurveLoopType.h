#ifndef _CURVE_LOOP_TYPE_H
#define _CURVE_LOOP_TYPE_H

namespace XNA
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