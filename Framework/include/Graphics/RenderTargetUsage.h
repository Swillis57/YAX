#ifndef _RENDER_TARGET_USAGE_H
#define _RENDER_TARGET_USAGE_H
						   

namespace XNA
{
	enum RenderTargetUsage : short
	{
		DiscardContents,
		PreserveContents,
		PlatformContents 
	};
}

#endif