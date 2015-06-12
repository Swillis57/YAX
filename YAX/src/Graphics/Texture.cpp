#include "../../include/Graphics/Texture.h"

#include "../../include/Graphics/SurfaceFormat.h"

namespace YAX
{
	Texture::Texture()
		: GraphicsResource("")
	{}

	Texture::~Texture()
	{
		if (_id != 0)
		{
			glDeleteTextures(1, &_id);
			_id = 0;
		}
	}

	Texture::Texture(Texture&& old)
		: _format(old._format),
		_levelCount(old._levelCount),
		_id(old._id),
		GraphicsResource(old._name)
	{
		old._id = 0;
		old._levelCount = 0;
		old._format = SurfaceFormat::Color;
	}

	Texture& Texture::operator=(Texture&& old)
	{
		this->_id = old._id;
		this->_levelCount = old._levelCount;
		this->_format = old._format;
		this->_name = old._name;

		old._id = 0;
		old._levelCount = 0;
		old._format = SurfaceFormat::Color;
		
		return *this;
	}

	SurfaceFormat Texture::Format() const
	{
		return _format;
	}

	void Texture::Format(SurfaceFormat sf)
	{
		_format = sf;
	}

	i32 Texture::LevelCount() const
	{
		return _levelCount;
	}

	void Texture::LevelCount(i32 levels)
	{
		_levelCount = levels;
	}
}