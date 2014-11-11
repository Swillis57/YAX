#ifndef _I_EFFECT_MATRICES_H
#define _I_EFFECT_MATRICES_H

#include "../Math/Matrix.h"

namespace XNA
{
	class IEffectMatrices
	{
	public:
		virtual ~IEffectMatrices() = 0;

		Matrix Projection() const;
		void Projection(const Matrix&);

		Matrix View() const;
		void View(const Matrix&);

		Matrix World() const;
		void World(const Matrix&);

	protected:
		Matrix _projection, _view, _world;
	};
}


#endif