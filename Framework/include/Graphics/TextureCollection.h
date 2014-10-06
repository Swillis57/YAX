#ifndef _TEXTURE_COLLECTION_H
#define _TEXTURE_COLLECTION_H

#include <vector>
#include "Texture.h"
#include "../Utils.h"


namespace XNA
{
	class TextureCollection
	{
	public:
		TextureCollection();
		Texture& operator[](i32);

	private:
		std::vector<Texture> _textures;
	};
}


#endif
