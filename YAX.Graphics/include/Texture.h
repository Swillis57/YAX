#ifndef _TEXTURE_H
#define _TEXTURE_H

#include "../../external/glew/include/GL/glew.h"
#include "GraphicsResource.h"
#include "../../Framework/include/Utils.h"

namespace YAX
{
	enum class SurfaceFormat : int;

	class GraphicsDevice;

	class Texture : public GraphicsResource
	{
	public:
		Texture(YAX::GraphicsDevice&);
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