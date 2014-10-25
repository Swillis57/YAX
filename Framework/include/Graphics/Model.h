#ifndef _MODEL_H
#define _MODEL_H

#include "ModelBone.h"
#include "ModelBoneCollection.h"
#include "ModelMeshCollection.h"

namespace XNA
{
	class Matrix;

	class Model
	{
	public:
		ModelBoneCollection Bones();

		ModelMeshCollection Meshes();

		ModelBone Root();

		void* Tag();
		void Tag(void*);

		void CopyAbsoluteBoneTransformsTo(std::vector<Matrix>&);

		void CopyBoneTransformsFrom(const std::vector<Matrix>&);

		void CopyBoneTransformsTo(std::vector<Matrix>&);

		void Draw();

	private:
		ModelBoneCollection _bones;
		ModelMeshCollection _meshes;
		ModelBone _root;
	};
}

#endif
