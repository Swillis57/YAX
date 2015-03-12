#ifndef _BLEND_H
#define _BLEND_H

#include "../../external/glew/include/GL/glew.h"

namespace YAX
{
	enum class Blend : int 
	{
		Zero = GL_ZERO,
		One = GL_ONE,
		SourceColor = GL_SRC_COLOR,
		InverseSourceColor = GL_ONE_MINUS_SRC_COLOR,
		SourceAlpha = GL_SRC_ALPHA,
		InverseSourceAlpha = GL_ONE_MINUS_SRC_ALPHA,
		DestinationAlpha = GL_DST_ALPHA,
		InverseDestinationAlpha = GL_ONE_MINUS_DST_ALPHA,
		DestinationColor = GL_DST_COLOR,
		InverseDestinationColor = GL_ONE_MINUS_DST_COLOR,
		SourceAlphaSaturation,
		BlendFactor,
		InverseBlendFactor
	};
}

#endif