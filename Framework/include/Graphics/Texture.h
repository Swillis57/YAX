#ifndef _TEXTURE_H
#define _TEXTURE_H

#include "../Glew/glew.h"
#include "GraphicsResource.h"
#include "../Utils.h"

namespace XNA
{
	enum class SurfaceFormat : int;

	class GraphicsDevice;

	class Texture : public GraphicsResource
	{
	public:
		Texture(XNA::GraphicsDevice&);
		virtual ~Texture() = 0;

		SurfaceFormat Format() const;
		i32 LevelCount() const;

	protected:
		void Format(SurfaceFormat);
		void LevelCount(int);

		SurfaceFormat _format;
		i32 _levelCount;
		GLuint _id;

	};
}


#endif