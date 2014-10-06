#ifndef _I_EFFECT_MATRICES_H
#define _I_EFFECT_MATRICES_H

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