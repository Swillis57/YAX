#ifndef _RENDER_TARGET_USAGE_H
#define _RENDER_TARGET_USAGE_H
						   

namespace XNA
{
	enum class RenderTargetUsage : int 
	{
		DiscardContents,
		PreserveContents,
		PlatformContents 
	};
}

#endif