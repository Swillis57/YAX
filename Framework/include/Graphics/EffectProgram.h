#ifndef _EFFECT_PROGRAM_H
#define _EFFECT_PROGRAM_H

#include <string>

#include "../GLEW/glew.h"

namespace XNA
{
	//An EffectProgram represents a single shader program
	class EffectProgram
	{
	public:
		EffectProgram(std::string, std::string);
		EffectProgram(const EffectProgram&) = delete;
		EffectProgram& operator=(const EffectProgram&) = delete;
		EffectProgram(EffectProgram&&);
		EffectProgram& operator=(EffectProgram&&);
		

		std::string Name();

		GLuint ID();
		

	private:
		std::string _name;
		GLuint _id;
	};
}


#endif