#ifndef _VERTEX_ELEMENT_USAGE_H
#define _VERTEX_ELEMENT_USAGE_H

#include "../GLEW/glew.h"

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