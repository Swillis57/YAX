#ifndef _SAMPLER_STATE_COLLECTION_H
#define _SAMPLER_STATE_COLLECTION_H

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