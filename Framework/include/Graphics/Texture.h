#ifndef _TEXTURE_H
#define _TEXTURE_H

#include "GraphicsResource.h"

namespace XNA
{
	enum class SurfaceFormat : int;

	class GraphicsDevice;

	class Texture : public GraphicsResource
	{
	public:
		Texture(XNA::GraphicsDevice&);
		virtual ~Texture();

		SurfaceFormat Format();
		int LevelCount();

	private:
		void Format(SurfaceFormat);
		void LevelCount(int);

		SurfaceFormat _format;
		int _levelCount;

	};
}


#endif