#ifndef _VERTEX_ELEMENT_FORMAT_H
#define _VERTEX_ELEMENT_FORMAT_H


#include <tuple>
#include "../GL/glew.h"

namespace XNA
{
	
	struct VertexElementFormat
	{
		
		std::tuple<GLenum, GLuint> data;

		static const VertexElementFormat Single;	        //<GL_FLOAT, 1>
		static const VertexElementFormat Vector2;	        //<GL_FLOAT, 2>
		static const VertexElementFormat Vector3;	        //<GL_FLOAT, 3>
		static const VertexElementFormat Vector4;	        //<GL_FLOAT, 4>
		static const VertexElementFormat HalfVector2;       //<GL_FLOAT, 2>
		static const VertexElementFormat HalfVector4;       //<GL_FLOAT, 4>
		static const VertexElementFormat Color;			    //<GL_UNSIGNED_BYTE, 4> 
		static const VertexElementFormat NormalizedShort2;  //<GL_UNSIGNED_SHORT, 2>
		static const VertexElementFormat NormalizedShort4;  //<GL_UNSIGNED_SHORT, 2>
		static const VertexElementFormat Short2;		    //<GL_SHORT, 2>			
		static const VertexElementFormat Short4;		    //<GL_SHORT, 4>			
		static const VertexElementFormat Byte42;		    //<GL_UNSIGNED_BYTE, 4> 

	private:
		VertexElementFormat(GLenum, GLuint);
	};

}


#endif