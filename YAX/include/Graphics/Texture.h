#ifndef _TEXTURE_H
#define _TEXTURE_H

#include "../../../external/glew/include/GL/glew.h"
#include "GraphicsResource.h"
#include "../Utils.h"

namespace YAX
{
	enum class SurfaceFormat : ui32;

	class Texture : public GraphicsResource
	{
	public:
		Texture();
		virtual ~Texture();
		
		Texture(const Texture&) = delete;
		Texture& operator=(const Texture&) = delete;
		Texture(Texture&&);
		Texture& operator=(Texture&&);

		SurfaceFormat Format() const;
		i32 LevelCount() const;

	protected:
		void Format(SurfaceFormat);
		void LevelCount(i32);

		SurfaceFormat _format;
		i32 _levelCount;
		GLuint _id;

	};
}


#endif