#ifndef TEXTURE_2D
#define TEXTURE_2D

#include <istream>
#include "Texture.h"
#include "../Utils.h"


namespace XNA
{
	class GraphicsDevice;
	class Rectangle;
	
	template<typename T>
	class Nullable;

	enum SurfaceFormat : short;

	class Texture2D : Texture
	{
	public:
		Texture2D(XNA::GraphicsDevice&, i32, i32);
		Texture2D(XNA::GraphicsDevice&, i32, i32, bool, SurfaceFormat);
		~Texture2D();

		Rectangle Bounds();
		i32 Height();
		i32 Width();

		Texture2D FromStream(XNA::GraphicsDevice&, const std::istream&);
		Texture2D FromStream(XNA::GraphicsDevice&, const std::istream&, i32, i32, bool);



	private:
		i32 _height, width;

	};
}


#endif