#include "CurveKey.h"
#include "CurveContinuity.h"

namespace YAX
{
	struct CurveKey::Impl
	{
		float _pos, _tanIn, _tanOut, _val;
		CurveContinuity _continuity;

		Impl(float pos, float val)
		  : _pos(pos), _val(val),
			_tanIn(0.0f), _tanOut(0.0f),
			_continuity(CurveContinuity::Smooth)
		{}

		Impl(float pos, float val, float tangentIn, float tangentOut)
			: _pos(pos), _val(val),
			_tanIn(tangentIn), _tanOut(tangentOut),
			_continuity(CurveContinuity::Smooth)
		{}

		Impl(float pos, float val, float tangentIn, float tangentOut, CurveContinuity continuity)
			: _pos(pos), _val(val),
			_tanIn(tangentIn), _tanOut(tangentOut),
			_continuity(continuity)
		{}

		~Impl() = default;

		bool operator==(const Impl& rhs)
		{
			return (this->_pos == rhs._pos
				 && this->_val == rhs._val
				 && this->_tanIn == rhs._tanIn
				 && this->_tanOut == rhs._tanOut
				 && this->_continuity == rhs._continuity);
		}

		bool operator!=(const Impl& rhs)
		{
			return !(*this == rhs);
		}
	};


	CurveKey::CurveKey(float pos, float val)
	{
		_impl = std::make_unique<Impl>(Impl(pos, val));
	}

	CurveKey::CurveKey(float pos, float val, float tangentIn, float tangentOut)
	{
		_impl = std::make_unique<Impl>(Impl(pos, val, tangentIn, tangentOut));
	}

	CurveKey::CurveKey(float pos, float val, float tangentIn, float tangentOut, CurveContinuity continuity)
	{
		_impl = std::make_unique<Impl>(Impl(pos, val, tangentIn, tangentOut, continuity));
	}

	CurveKey::~CurveKey() = default;

	float CurveKey::Position() const
	{
		return _impl->_pos;
	}

	float CurveKey::TangentIn() const
	{
		return _impl->_tanIn;
	}

	void CurveKey::TangentIn(float tangentIn)
	{
		_impl->_tanIn = tangentIn;
	}

	float CurveKey::TangentOut() const
	{
		return _impl->_tanOut;
	}

	void CurveKey::TangentOut(float tangentOut)
	{
		_impl->_tanOut = tangentOut;
	}

	float CurveKey::Value() const
	{
		return _impl->_val;
	}

	void CurveKey::Value(float val)
	{
		_impl->_val = val;
	}

	CurveContinuity CurveKey::Continuity() const
	{
		return _impl->_continuity;
	}

	void CurveKey::Continuity(CurveContinuity continuity)
	{
		_impl->_continuity = continuity;
	}
	
	bool operator==(const CurveKey& lhs, const CurveKey& rhs)
	{
		return (*lhs._impl == *rhs._impl);
	}
	
	bool operator!=(const CurveKey& lhs, const CurveKey& rhs)
	{
		return !(lhs == rhs);
	}
}
