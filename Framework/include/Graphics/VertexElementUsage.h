#ifndef VERTEX_ELEMENT_USAGE
#define VERTEX_ELEMENT_USAGE

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