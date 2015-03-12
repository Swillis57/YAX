#ifndef _GRAPHICS_DEVICE_H
#define _GRAPHICS_DEVICE_H

//Template specialization hacks for GraphicsDevice.cpp (Move once created)

#define DUIP_SPECIALIZE(vertType) \
	template void DrawUserIndexedPrimitives<vertType>(PrimitiveType, std::vector<vertType>&, i32, i32, const std::vector<i16>&, i32, i32) const; \
	template void DrawUserIndexedPrimitives<vertType>(PrimitiveType, std::vector<vertType>&, i32, i32, const std::vector<i16>&, i32, i32, const VertexDeclaration&) const; \
	template void DrawUserIndexedPrimitives<vertType>(PrimitiveType, std::vector<vertType>&, i32, i32, const std::vector<i32>&, i32, i32) const; \
	template void DrawUserIndexedPrimitives<vertType>(PrimitiveType, std::vector<vertType>&, i32, i32, const std::vector<i32>&, i32, i32, const VertexDeclaration&) const;

#define DUP_SPECIALIZE(vertType) \
	template void DrawUserPrimitives<vertType>(PrimitiveType, std::vector<vertType>&, i32, i32) const; \
	template void DrawUserPrimitives<vertType>(PrimitiveType, std::vector<vertType>&, i32, i32, const VertexDeclaration&) const;

#define BBD_SPECIALIZE(dataType) \
	template void GetBackBufferData<dataType>(std::unique_ptr<Rectangle>, std::vector<T>&, i32, i32) const; \
	template void GetBackBufferData<dataType>(std::vector<dataType>&) const; \
	template void GetBackBufferData<dataType>(std::vector<dataType>&, i32, i32) const;


#include <memory>
#include <vector>

#include "GraphicsAdapter.h"
#include "BlendState.h"
#include "../../Framework/include/Color.h"
#include "DepthStencilState.h"
#include "DisplayMode.h"
#include "IndexBuffer.h"
#include "PresentationParameters.h"
#include "RasterizerState.h"		
#include "RenderTarget2D.h"
#include "RenderTargetCube.h"
#include "../../Framework.Geometry/include/Rectangle.h"
#include "SamplerStateCollection.h"
#include "TextureCollection.h"
#include "../../Framework/include/Utils.h"
#include "Viewport.h"


namespace YAX
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
		GraphicsDevice(const GraphicsAdapter&, const GraphicsProfile&, const YAX::PresentationParameters&);

		GraphicsAdapter& Adapter() const;

		Color BlendFactor() const;
		void BlendFactor(Color);

		YAX::BlendState& BlendState() const;
		void BlendState(YAX::BlendState);

		YAX::DepthStencilState& DepthStencilState() const;
		void DepthStencilState(YAX::DepthFormat);
				
		YAX::DisplayMode& DisplayMode() const;

		YAX::GraphicsProfile GraphicsProfile() const;

		IndexBuffer& Indicies() const;
		void Indicies(IndexBuffer);

		i32 MultiSampleMask() const;
		void MultiSampleMask(i32);

		YAX::PresentationParameters& PresentationParameters() const;

		YAX::RasterizerState RasterizerState() const;
		void RasterizerState(YAX::RasterizerState);

		i32 ReferenceStencil() const;
		void ReferenceStencil(i32);

		Rectangle ScissorRectangle() const;
		void ScissorRectangle(Rectangle);

		SamplerStateCollection& VertexSamplerStates() const;

		TextureCollection& Textures() const;

		TextureCollection& VertexTextures() const;

		YAX::Viewport Viewport() const;
		void Viewport(YAX::Viewport);
#pragma endregion

		void Clear(ClearOptions) const;
		void Clear(ClearOptions, const Color&, float, i32) const;
		void Clear(ClearOptions, const Vector4, float, i32) const;
		void Clear(const Color&) const;
		
		void DrawIndexedPrimitives(PrimitiveType, i32, i32, i32, i32, i32) const;
		void DrawInstancedPrimitives(PrimitiveType, i32, i32, i32, i32, i32, i32) const;
		void DrawPrimitives(PrimitiveType, i32, i32) const;
		
		template<typename T>
		void DrawUserIndexedPrimitives(PrimitiveType, std::vector<T>&, i32, i32, const std::vector<i16>&, i32, i32) const;
		template<typename T>
		void DrawUserIndexedPrimitives(PrimitiveType, std::vector<T>&, i32, i32, const std::vector<i16>&, i32, i32, const VertexDeclaration&) const;
		template<typename T>
		void DrawUserIndexedPrimitives(PrimitiveType, std::vector<T>&, i32, i32, const std::vector<i32>&, i32, i32) const;
		template<typename T>
		void DrawUserIndexedPrimitives(PrimitiveType, std::vector<T>&, i32, i32, const std::vector<i32>&, i32, i32, const VertexDeclaration&) const;

		template<typename T>
		void DrawUserPrimitives(PrimitiveType, std::vector<T>&, i32, i32) const;
		template<typename T>
		void DrawUserPrimitives(PrimitiveType, std::vector<T>&, i32, i32, const VertexDeclaration&) const;

		template<typename T>
		void GetBackBufferData(std::unique_ptr<Rectangle>, std::vector<T>&, i32, i32) const;
		template<typename T>
		void GetBackBufferData(std::vector<T>&) const;
		template<typename T>
		void GetBackBufferData(std::vector<T>&, i32, i32) const;
		 
		std::vector<RenderTargetBinding> GetRenderTargets() const;

		std::vector<VertexBufferBinding> GetVertexBuffers() const;

		void Present() const;
		void Present(std::unique_ptr<Rectangle>, std::unique_ptr<Rectangle>, std::shared_ptr<int>) const;

		void Reset() const;
		void Reset(const YAX::PresentationParameters&) const;
		void Reset(const YAX::PresentationParameters&, const GraphicsAdapter&) const;

		void SetRenderTarget(const RenderTarget2D&);
		void SetRenderTarget(const RenderTargetCube&, CubeMapFace);

		void SetRenderTargets(const std::vector<RenderTargetBinding>&);

		void SetVertexBuffer(const VertexBuffer&);
		void SetVertexBuffer(const VertexBuffer&, i32);

		void SetVertexBuffers(const std::vector<VertexBuffer>&);

	private:
		GraphicsAdapter _adapter;
		YAX::BlendState _blendState;
		YAX::DepthStencilState _depthStencilState;
		YAX::DisplayMode _displayMode;
		YAX::GraphicsProfile _graphicsProfile;
		IndexBuffer _indices;
		i32 _msMask, _refStencil;
		YAX::PresentationParameters _presParams;
		YAX::RasterizerState _rasterState;
		Rectangle _scissorRect;
		SamplerStateCollection _samplerStates;
		TextureCollection _textures, _vertTextures;
		YAX::Viewport _viewport;
	};
}
#endif