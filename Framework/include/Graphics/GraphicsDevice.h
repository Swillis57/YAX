#ifndef _GRAPHICS_DEVICE_H
#define _GRAPHICS_DEVICE_H



#include <vector>
#include "GraphicsAdapter.h"
#include "BlendState.h"
#include "../Color.h"
#include "DepthStencilState.h"
#include "DisplayMode.h"
#include "IndexBuffer.h"
#include <memory>
#include "PresentationParameters.h"
#include "RasterizerState.h"		
#include "RenderTarget2D.h"
#include "RenderTargetCube.h"
#include "../Geometry/Rectangle.h"
#include "SamplerStateCollection.h"
#include "TextureCollection.h"
#include "../Utils.h"
#include "Viewport.h"


namespace XNA
{ 
	enum class GraphicsProfile : int;
	enum class PrimitiveType : int;
	enum class ClearOptions : int;

	class Vector4;
	class VertexDeclaration;
	class RenderTargetBinding;
	class VertexBufferBinding;
	class VertexBuffer;

	class GraphicsDevice
	{
	public:
		#pragma region Properties
		GraphicsDevice(GraphicsAdapter, GraphicsProfile, PresentationParameters);

		GraphicsAdapter const Adapter();

		Color BlendFactor();
		void BlendFactor(Color);

		XNA::BlendState BlendState();
		void BlendState(XNA::BlendState);

		XNA::DepthStencilState DepthStencilState();
		void DepthStencilState(XNA::DepthFormat);
				
		XNA::DisplayMode DisplayMode();
		void DisplayMode(XNA::DisplayMode);

		XNA::GraphicsProfile GraphicsProfile();

		IndexBuffer Indicies();
		void Indicies(IndexBuffer);

		i32 MultiSampleMask();
		void MultiSampleMask(i32);

		XNA::PresentationParameters PresentationParameters();

		XNA::RasterizerState RasterizerState();
		void RasterizerState(XNA::RasterizerState);

		int ReferenceStencil();
		void ReferenceStencil(int);

		Rectangle ScissorRectangle();
		void ScissorRectangle(Rectangle);

		TextureCollection Textures();
		void Textures(TextureCollection);

		SamplerStateCollection VertexSamplerStates();

		TextureCollection VertexTextures();

		XNA::Viewport Viewport();
		void Viewport(XNA::Viewport);
#pragma endregion

		void Clear(ClearOptions, const Color&, float, i32);
		void Clear(ClearOptions, const Vector4, float, i32);
		void Clear(const Color&);
		
		void DrawIndexedPrimitives(PrimitiveType, i32, i32, i32, i32, i32);
		void DrawInstancedPrimitives(PrimitiveType, i32, i32, i32, i32, i32, i32);
		void DrawPrimitives(PrimitiveType, i32, i32);

		template<typename T>
		void DrawUserIndexedPrimitives(PrimitiveType, std::vector<T>, i32, i32, std::vector<i16>, i32, i32);
		template<typename T>
		void DrawUserIndexedPrimitives(PrimitiveType, std::vector<T>, i32, i32, std::vector<i16>, i32, i32, VertexDeclaration);
		template<typename T>
		void DrawUserIndexedPrimitives(PrimitiveType, std::vector<T>, i32, i32, std::vector<i32>, i32, i32);
		template<typename T>
		void DrawUserIndexedPrimitives(PrimitiveType, std::vector<T>, i32, i32, std::vector<i32>, i32, i32, VertexDeclaration);

		template<typename T>
		void DrawUserPrimitives(PrimitiveType, std::vector<T>, i32, i32);
		template<typename T>
		void DrawUserPrimitives(PrimitiveType, std::vector<T>, i32, i32, VertexDeclaration);

		template<typename T>
		void GetBackBufferData(std::unique_ptr<Rectangle>, std::vector<T>, i32, i32);
		template<typename T>
		void GetBackBufferData(std::vector<T>);
		template<typename T>
		void GetBackBufferData(std::vector<T>, i32, i32);

		std::vector<RenderTargetBinding> GetRenderTargets();

		std::vector<VertexBufferBinding> GetVertexBuffers();

		void Present();
		void Present(std::unique_ptr<Rectangle>, std::unique_ptr<Rectangle>, std::shared_ptr<int>);

		void Reset();
		void Reset(const XNA::PresentationParameters&);
		void Reset(const XNA::PresentationParameters&, const GraphicsAdapter&);

		void SetRenderTarget(RenderTarget2D);
		void SetRenderTarget(RenderTargetCube, CubeMapFace);

		void SetRenderTargets(std::vector<RenderTargetBinding>);

		void SetVertexBuffer(VertexBuffer&);
		void SetVertexBuffer(VertexBuffer&, i32);

		void SetVertexBuffers(std::vector<VertexBuffer>);
	};
}
#endif