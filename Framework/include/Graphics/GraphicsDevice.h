#ifndef GRAPHICS_DEVICE
#define GRAPHICS_DEVICE

#include "GraphicsAdapter.h"
#include "BlendState.h"
#include "GraphicsProfile.h"
#include "../Color.h"
#include "DepthStencilState.h"
#include "DisplayMode.h"
#include "GraphicsProfile.h"



namespace XNA
{
	class GraphicsAdapter;
	class PresentationParameters;

	class GraphicsDevice
	{
	public:
		GraphicsDevice(const GraphicsAdapter&, GraphicsProfile, const PresentationParameters&);

		const GraphicsAdapter& Adapter();

		Color BlendFactor();
		void BlendFactor(const Color&);

		XNA::BlendState BlendState();
		void BlendState(XNA::BlendState);

		XNA::DepthStencilState DepthStencilState();
		void DepthStencilState(XNA::DepthFormat);
				
		XNA::DisplayMode DisplayMode();
		void DisplayMode(XNA::DisplayMode);

		XNA::GraphicsProfile GraphicsProfile();


	};
}
#endif