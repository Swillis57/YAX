#ifndef _DISPLAY_MODE_COLLECTION_H
#define _DISPLAY_MODE_COLLECTION_H

#include <map>
#include "DisplayMode.h"

namespace XNA
{		 
	enum class SurfaceFormat : int;
	typedef std::map<SurfaceFormat, DisplayMode> DisplayModeCollection;
}


#endif