#ifndef _TEXTURE_3D_H
#define _TEXTURE_3D_H

#define T3D_SPECIALIZE(dataType) \
	template void GetData<dataType>(i32, i32, i32, i32, i32, i32, std::vector<dataType>&, i32, i32) const; \
	template void GetData<dataType>(std::vector<dataType>&) const; \
	template void GetData<dataType>(std::vector<dataType>, i32, i32) const; \
	template void SetData<dataType>(i32, i32, i32, i32, i32, i32, std::vector<dataType>&, i32, i32); \
	template void SetData<dataType>(std::vector<dataType>&); \
	template void SetData<dataType>(std::vector<dataType>, i32, i32);



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
		Texture3D(const Texture3D&) = delete;
		Texture3D operator=(const Texture3D&) = delete;
		Texture3D(Texture3D&&);
		Texture3D& operator=(Texture3D&&);

		i32 Depth() const;

		i32 Height() const;

		i32 Width() const;

		template<typename dataType>
		GetData(i32, i32, i32, i32, i32, i32, std::vector<dataType>&, i32, i32) const;
		template<typename dataType>
		GetData(std::vector<dataType>&) const;
		template<typename dataType>
		GetData(std::vector<dataType>, i32, i32) const;

		template<typename dataType>
		SetData(i32, i32, i32, i32, i32, i32, const std::vector<dataType>&, i32, i32);
		template<typename dataType>
		SetData(const std::vector<dataType>&);
		template<typename dataType>
		SetData(const std::vector<dataType>, i32, i32);

	private:
		i32 _depth, _width, _height;
	};
}


#endif