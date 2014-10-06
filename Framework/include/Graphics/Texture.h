#ifndef _TEXTURE_H
#define _TEXTURE_H

#include "GraphicsResource.h"

namespace XNA
{
	enum SurfaceFormat : short;

	class Texture : public GraphicsResource
	{
	public:
		Texture();
		~Texture();

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