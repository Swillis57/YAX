#ifndef _VERTEX_ELEMENT_USAGE_H
#define _VERTEX_ELEMENT_USAGE_H

#include "../GLEW/glew.h"

namespace XNA
{
	enum class VertexElementUsage
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