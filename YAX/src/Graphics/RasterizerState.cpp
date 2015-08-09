#include "Graphics/RasterizerState.h"

#include "Graphics/CullMode.h"
#include "Graphics/FillMode.h"

namespace YAX
{
	const RasterizerState RasterizerState::CullClockwise(CullMode::CullClockwiseFace);
	const RasterizerState RasterizerState::CullCounterClockwise(CullMode::CullCounterClockwiseFace);
	const RasterizerState RasterizerState::CullNone(CullMode::None);

	RasterizerState::RasterizerState()
		: _cullMode(CullMode::CullCounterClockwiseFace),
		_fillMode(FillMode::Solid),
		_scissorTest(false),
		_msaa(true),
		_depthBias(0),
		_slopeScaleDepthBias(0)
	{}

	RasterizerState::RasterizerState(YAX::CullMode cm)
		: _cullMode(cm),
		_fillMode(FillMode::Solid),
		_scissorTest(false),
		_msaa(true),
		_depthBias(0),
		_slopeScaleDepthBias(0)
	{}

	YAX::CullMode RasterizerState::CullMode() const
	{
		return _cullMode;
	}

	void RasterizerState::CullMode(YAX::CullMode cm)
	{
		_cullMode = cm;
	}

	float RasterizerState::DepthBias() const
	{
		return _depthBias;
	}

	void RasterizerState::DepthBias(float db)
	{
		_depthBias = db;
	}

	YAX::FillMode RasterizerState::FillMode() const
	{
		return _fillMode;
	}

	void RasterizerState::FillMode(YAX::FillMode fm)
	{
		_fillMode = fm;
	}

	bool RasterizerState::MultiSampleAntiAlias() const
	{
		return _msaa;
	}

	void RasterizerState::MultiSampleAntiAlias(bool ms)
	{
		_msaa = ms;
	}

	bool RasterizerState::ScissorTestEnable() const
	{
		return _scissorTest;
	}

	void RasterizerState::ScissorTestEnable(bool st)
	{
		_scissorTest = st;
	}

	float RasterizerState::SlopeScaleDepthBias() const
	{
		return _slopeScaleDepthBias;
	}

	void RasterizerState::SlopeScaleDepthBias(float ssdb)
	{
		_slopeScaleDepthBias = ssdb;
	}

}