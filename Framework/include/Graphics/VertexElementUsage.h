#ifndef _VERTEX_ELEMENT_USAGE_H
#define _VERTEX_ELEMENT_USAGE_H

#include "../gl/glew.h"

namespace XNA
{
	enum VertexElementUsage : short
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