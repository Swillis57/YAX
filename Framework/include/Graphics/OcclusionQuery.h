#ifndef _OCCLUSION_QUERY_H
#define _OCCLUSION_QUERY_H

#include "GraphicsResource.h"
#include "../Utils.h"

namespace XNA
{
	class GraphicsDevice;

	class OcclusionQuery : public GraphicsResource
	{
	public:
		OcclusionQuery(const XNA::GraphicsDevice&);

		bool IsComplete();

		i32 PixelCount();

		void Begin();
		
		void End();

	private:
		i32 _pixelCount;
	};
}


#endif
