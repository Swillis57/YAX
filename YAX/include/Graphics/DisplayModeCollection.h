#ifndef _DISPLAY_MODE_COLLECTION_H
#define _DISPLAY_MODE_COLLECTION_H

#include <unordered_map>
#include "DisplayMode.h"

namespace YAX
{		 
	enum class SurfaceFormat : ui32;
	typedef std::unordered_map<SurfaceFormat, DisplayMode> DisplayModeCollection;
}


#endif