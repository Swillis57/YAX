#ifndef _MODEL_H
#define _MODEL_

#include "ModelBoneCollection.h"
#include "ModelMeshCollection.h"

namespace XNA
{
	class Model
	{
	public:
		ModelBoneCollection Bones();

		ModelMeshCollection Meshes();

		ModelBone Root();

		void* Tag();
		void Tag(void*);
	};
}

#endif
