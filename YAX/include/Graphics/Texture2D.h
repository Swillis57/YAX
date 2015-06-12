#ifndef _TEXTURE_2D_H
#define _TEXTURE_2D_H


#define T2D_SPECIALIZE(valType) \
	template void GetData<valType>(i32, std::unique_ptr<Rectangle>, std::vector<valType>, i32, i32) const; \
	template void GetData<valType>(std::vector<valType>) const; \
	template void GetData<valType>(std::vector<valType>, i32, i32) const; \
	template void SetData<valType>(i32, std::unique_ptr<Rectangle>, std::vector<valType>, i32, i32) const; \
	template void SetData<valType>(std::vector<valType>) const; \
	template void SetData<valType>(std::vector<valType>, i32, i32) const;

#include <istream>
#include <vector>
#include "Texture.h"
#include "../Utils.h"


namespace YAX
{
	class GraphicsDevice;
	struct Rectangle;

	enum class SurfaceFormat : ui32;

	class Texture2D : public Texture
	{
	public:
		Texture2D(YAX::GraphicsDevice&, i32, i32);
		Texture2D(YAX::GraphicsDevice&, i32, i32, bool, SurfaceFormat);
		Texture2D(const Texture2D&) = delete;
		Texture2D& operator=(const Texture2D&) = delete;
		Texture2D(Texture2D&&);
		Texture2D& operator=(Texture2D&&);
		~Texture2D();

		Rectangle Bounds() const;
		i32 Height() const;
		i32 Width() const;

		static Texture2D FromStream(YAX::GraphicsDevice&, const std::istream&);
		static Texture2D FromStream(YAX::GraphicsDevice&, const std::istream&, i32, i32, bool);

		template<typename valType>
		void GetData(i32, std::unique_ptr<Rectangle>, std::vector<valType>&, i32, i32) const;
		template<typename valType>
		void GetData(std::vector<valType>&) const;
		template<typename valType>
		void GetData(std::vector<valType>&, i32, i32) const;

		template<typename valType>
		void SetData(i32, std::unique_ptr<Rectangle>, const std::vector<valType>&, i32, i32);
		template<typename valType>
		void SetData(const std::vector<valType>&);
		template<typename valType>
		void SetData(const std::vector<valType>&, i32, i32);

		void SaveAsJpeg(std::istream&, i32, i32) const;
		void SaveAsPng(std::istream&, i32, i32) const;

	private:
		i32 _height, _width;

	};
}


#endif