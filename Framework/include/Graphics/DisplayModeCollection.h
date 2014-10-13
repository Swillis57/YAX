#ifndef _DISPLAY_MODE_COLLECTION_H
#define _DISPLAY_MODE_COLLECTION_H

#include <map>
#include "DisplayMode.h"

namespace XNA
{		 
	enum SurfaceFormat : short;
	typedef std::map<SurfaceFormat, DisplayMode> DisplayModeCollection;
}


#endif