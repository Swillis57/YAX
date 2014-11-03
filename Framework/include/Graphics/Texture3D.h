#ifndef _TEXTURE_3D_H
#define _TEXTURE_3D_H

#include <vector>
#include "Texture.h"
#include "../Utils.h"

namespace XNA
{
	enum class SurfaceFormat : int;

	class GraphicsDevice;

	class Texture3D : public Texture
	{
	public:
		Texture3D(XNA::GraphicsDevice&, i32, i32, i32, bool, SurfaceFormat);

		i32 Depth();

		i32 Height();

		i32 Width();

		template<typename dataType>
		GetData(i32, i32, i32, i32, i32, i32, std::vector<dataType>&, i32, i32);
		template<typename dataType>
		GetData(std::vector<dataType>&);
		template<typename dataType>
		GetData(std::vector<dataType>, i32, i32);

		template<typename dataType>
		SetData(i32, i32, i32, i32, i32, i32, std::vector<dataType>&, i32, i32);
		template<typename dataType>
		SetData(std::vector<dataType>&);
		template<typename dataType>
		SetData(std::vector<dataType>, i32, i32);

	private:
		i32 _depth, _width, _height;
		std::vector<i32> _data;
	};
}


#endif