#ifndef GRAPHICS_DEVICE
#define GRAPHICS_DEVICE

#include "GraphicsAdapter.h"
#include "BlendState.h"
#include "../Color.h"
#include "DepthStencilState.h"
#include "DisplayMode.h"
#include "GraphicsProfile.h"
#include "IndexBuffer.h"
#include "PresentationParameters.h"
#include "RasterizerState.h"
#include "../Geometry/Rectangle.h"



namespace XNA
{
	enum GraphicsProfile : short;
	

	class GraphicsDevice
	{
	public:
		GraphicsDevice(GraphicsAdapter&&, GraphicsProfile, PresentationParameters&&);

		GraphicsAdapter const Adapter();

		Color BlendFactor();
		void BlendFactor(const Color&);

		XNA::BlendState BlendState();
		void BlendState(XNA::BlendState);

		XNA::DepthStencilState DepthStencilState();
		void DepthStencilState(XNA::DepthFormat);
				
		XNA::DisplayMode DisplayMode();
		void DisplayMode(XNA::DisplayMode);

		XNA::GraphicsProfile GraphicsProfile();

		IndexBuffer Indicies();
		void Indicies(IndexBuffer&&);

		i32 MultiSampleMask();
		void MultiSampleMask(i32);

		XNA::PresentationParameters PresentationParameters();

		XNA::RasterizerState RasterizerState();
		void RasterizerState(XNA::RasterizerState);

		int ReferenceStencil();
		void ReferenceStencil(int);

		Rectangle ScissorRectangle();
		void ScissorRectangle(const Rectangle&);



	};
}
#endif