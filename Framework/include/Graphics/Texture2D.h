#ifndef TEXTURE_2D
#define TEXTURE_2D

#include <istream>
#include <vector>
#include "Texture.h"
#include "GraphicsResource.h"
#include "../Utils.h"


namespace XNA
{
	class GraphicsDevice;
	class Rectangle;
	
	template<typename T>
	class Nullable;

	enum SurfaceFormat : short;

	class Texture2D : public Texture, public GraphicsResource
	{
	public:
		Texture2D(XNA::GraphicsDevice&, i32, i32);
		Texture2D(XNA::GraphicsDevice&, i32, i32, bool, SurfaceFormat);
		~Texture2D();

		Rectangle Bounds();
		i32 Height();
		i32 Width();

		static Texture2D FromStream(XNA::GraphicsDevice&, const std::istream&);
		static Texture2D FromStream(XNA::GraphicsDevice&, const std::istream&, i32, i32, bool);

		template<typename valType>
		void GetData(i32, Nullable<Rectangle>, std::vector<valType>, i32, i32);
		template<typename valType>
		void GetData(std::vector<valType>);
		template<typename valType>
		void GetData(std::vector<valType>, i32, i32);

		void SaveAsJpeg(std::istream&, i32, i32);
		void SaveAsPng(std::istream&, i32, i32);

		template<typename valType>
		void SetData(i32, Nullable<Rectangle>, std::vector<valType>, i32, i32);
		template<typename valType>
		void SetData(std::vector<valType>);
		template<typename valType>
		void SetData(std::vector<valType>, i32, i32);


	private:
		i32 _height, _width;

	};
}


#endif