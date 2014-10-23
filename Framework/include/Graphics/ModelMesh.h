#ifndef _MODEL_MESH_H
#define _MODEL_MESH_H

#include <string>
#include "ModelBone.h"

namespace XNA
{
	class BoundingSphere;
	class ModelEffectCollection;
	class ModelMeshPartCollection;

	class ModelMesh
	{	
	public:
		XNA::BoundingSphere BoundingSphere();

		ModelEffectCollection Effects();

		ModelMeshPartCollection MeshParts();

		std::string Name();

		ModelBone ParentBone();

		void* Tag();
		void Tag(void*);

		void Draw();

	private:


	};
}

#endif