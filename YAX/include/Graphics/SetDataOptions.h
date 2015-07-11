#ifndef _SET_DATA_OPTIONS_H
#define _SET_DATA_OPTIONS_H

#include "../../../external/glew/include/GL/glew.h"
#include "../Utils.h"

namespace YAX
{
	enum class SetDataOptions : GLbitfield 
	{
		Discard = GL_MAP_INVALIDATE_RANGE_BIT | GL_MAP_UNSYNCHRONIZED_BIT,
		None = 0,
		NoOverwrite = GL_MAP_UNSYNCHRONIZED_BIT,
	};
}


#endif
