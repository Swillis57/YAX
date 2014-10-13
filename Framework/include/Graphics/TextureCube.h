#ifndef _TEXTURE_CUBE_H
#define _TEXTURE_CUBE_H

#include <vector>
#include "Texture.h"
#include "../Nullable.h"
#include "../Utils.h"

namespace XNA
{
	enum CubeMapFace : short;
	enum SurfaceFormat : short;

	class GraphicsDevice;
	class Rectangle;
	
	class TextureCube : public Texture
	{
	public:
		TextureCube(XNA::GraphicsDevice&, i32, bool, SurfaceFormat);
		~TextureCube();

		i32 Size();

		template<typename T>
		void GetData(CubeMapFace, i32, Nullable<Rectangle>, std::vector<T>, i32, i32);
		template<typename T>
		void GetData(CubeMapFace, std::vector<T>);
		template<typename T>
		void GetData(CubeMapFace, std::vector<T>, i32, i32);

		template<typename T>
		void SetData(CubeMapFace, i32, Nullable<Rectangle>, std::vector<T>, i32, i32);
		template<typename T>
		void SetData(CubeMapFace, std::vector<T>);
		template<typename T>
		void SetData(CubeMapFace, std::vector<T>, i32, i32);
	};
}


#endif