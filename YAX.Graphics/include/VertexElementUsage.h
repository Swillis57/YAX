#ifndef _VERTEX_ELEMENT_USAGE_H
#define _VERTEX_ELEMENT_USAGE_H

#include "../../external/glew/include/GL/glew.h"

namespace YAX
{
	enum class VertexElementUsage : int 
	{
		Binormal,
		BlendIndices,
		BlendWeight,
		Color,
		Depth,
		Fog, 
		Normal,
		PointSize,
		Position,
		Sample,
		Tangent,
		TessellateFactor,
		TextureCoordinate
	};
}


#endif