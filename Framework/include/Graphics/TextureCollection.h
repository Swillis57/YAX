#ifndef TEXTURE_COLLECTION
#define TEXTURE_COLLECTION

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
