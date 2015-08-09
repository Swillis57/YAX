#ifndef _RENDER_TARGET_USAGE_H
#define _RENDER_TARGET_USAGE_H
						   
#include "../Utils.h"

namespace YAX
{
	enum class RenderTargetUsage : ui32 
	{
		DiscardContents,
		PreserveContents,
		PlatformContents 
	};
}

#endif