#ifndef SAMPLER_STATE_COLLECTION
#define SAMPLER_STATE_COLLECTION

#include <vector>
#include "../Utils.h"

namespace XNA
{
	class SamplerState;

	class SamplerStateCollection
	{
	public:
		SamplerStateCollection();
		SamplerState& operator[](i32);

	private:
		std::vector<SamplerState> _states;
	};	   
}


#endif