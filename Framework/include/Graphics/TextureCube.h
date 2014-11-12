#ifndef _TEXTURE_CUBE_H
#define _TEXTURE_CUBE_H

#include <vector>
#include "Texture.h"
#include <memory>
#include "../Utils.h"

namespace XNA
{
	enum class CubeMapFace : int;
	enum class SurfaceFormat : int;

	class GraphicsDevice;
	class Rectangle;
	
	class TextureCube : public Texture
	{
	public:
		TextureCube(XNA::GraphicsDevice&, i32, bool, SurfaceFormat);
		TextureCube(const TextureCube&) = delete;
		TextureCube& operator=(const TextureCube&) = delete;
		TextureCube(TextureCube&&);
		TextureCube& operator=(TextureCube&&);
		~TextureCube();

		i32 Size() const;

		template<typename T>
		void GetData(CubeMapFace, i32, std::unique_ptr<Rectangle>, const std::vector<T>&, i32, i32) const;
		template<typename T>
		void GetData(CubeMapFace, const std::vector<T>&) const;
		template<typename T>
		void GetData(CubeMapFace, const std::vector<T>&, i32, i32) const;

		template<typename T>
		void SetData(CubeMapFace, i32, std::unique_ptr<Rectangle>, const std::vector<T>&, i32, i32) const;
		template<typename T>
		void SetData(CubeMapFace, const std::vector<T>&) const;
		template<typename T>
		void SetData(CubeMapFace, const std::vector<T>&, i32, i32) const;
	};
}


#endif