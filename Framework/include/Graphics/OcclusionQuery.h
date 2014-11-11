#ifndef _OCCLUSION_QUERY_H
#define _OCCLUSION_QUERY_H

#include "../GLEW/glew.h"
#include "GraphicsResource.h"
#include "../Utils.h"

namespace XNA
{
	class GraphicsDevice;

	class OcclusionQuery : public GraphicsResource
	{
	public:
		OcclusionQuery(XNA::GraphicsDevice&);

		bool IsComplete() const;

		i32 PixelCount() const;

		void Begin() const;
		
		void End() const;

	private:
		i32 _pixelCount;
		GLuint _qID;
	};
}


#endif
