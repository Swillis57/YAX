#ifndef _GRAPHICS_DEVICE_H
#define _GRAPHICS_DEVICE_H

#include "GraphicsAdapter.h"
#include "BlendState.h"
#include "../Color.h"
#include "DepthStencilState.h"
#include "DisplayMode.h"
#include "GraphicsProfile.h"
#include "IndexBuffer.h"
#include "../Nullable.h"
#include "PresentationParameters.h"
#include "RasterizerState.h"
#include "../Geometry/Rectangle.h"
#include "SamplerStateCollection.h"
#include "TextureCollection.h"
#include "../Utils.h"
#include "Viewport.h"




namespace XNA
{ 
	enum GraphicsProfile : short;
	enum PrimitiveType : short;
	enum ClearOptions : short;

	class Vector4;

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
		void Clear(ClearOptions, const Vector4&, float, i32);
		void Clear(const Color&);
		
		void DrawIndexedPrimitives(PrimitiveType, i32, i32, i32, i32, i32);
		void DrawInstancedPrimitives(PrimitiveType, i32, i32, i32, i32, i32, i32);
		void DrawPrimitives(PrimitiveType, i32, i32);

		template<typename T>
		DrawUserIndexedPrimitives(PrimitiveType, std::vector<T>, i32, i32, vector<i16>, i32, i32);
		template<typename T>
		DrawUserIndexedPrimitives(PrimitiveType, std::vector<T>, i32, i32, vector<i16>, i32, i32, VertexDeclaration);
		template<typename T>
		DrawUserIndexedPrimitives(PrimitiveType, std::vector<T>, i32, i32, vector<i32>, i32, i32);
		template<typename T>
		DrawUserIndexedPrimitives(PrimitiveType, std::vector<T>, i32, i32, vector<i32>, i32, i32, VertexDeclaration);

		template<typename T>
		DrawUserPrimitives(PrimitiveType, std::vector<T>, i32, i32);
		template<typename T>
		DrawUserPrimitives(PrimitiveType, std::vector<T>, i32, i32, VertexDeclaration);

		template<typename T>
		GetBackBufferData(Nullable<Rectangle>, std::vector<T>, i32, i32);
		template<typename T>
		GetBackBufferData(std::vector<T>);
		template<typename T>
		GetBackBufferData(std::vector<T>, i32, i32);



	};
}
#endif