#ifndef _MODEL_BONE_H
#define _MODEL_BONE_H

#include <string>
#include "../Math/Matrix.h"
#include "ModelBoneCollection.h"
#include "../Utils.h"

namespace XNA
{
	class ModelBone
	{
	public:
		ModelBoneCollection Children();

		i32 Index();

		std::string Name();

		ModelBone Parent();

		Matrix Transform();

	private:
		ModelBoneCollection _children;
		i32 _idx;
		std::string _name;
		ModelBone& _parent;
		Matrix _transform;
	};
}


#endif
