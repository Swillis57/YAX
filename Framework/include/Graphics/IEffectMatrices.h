#ifndef I_EFFECT_MATRICES
#define I_EFFECT_MATRICES

#include "../Math/Matrix.h"

namespace XNA
{
	class IEffectMatrices
	{
	public:
		virtual ~IEffectMatrices();

		Matrix Projection, View, World;
	};
}


#endif