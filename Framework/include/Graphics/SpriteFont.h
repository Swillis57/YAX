#ifndef _SPRITE_FONT_H
#define _SPRITE_FONT_H

#include <string>
#include <vector>
#include "../Utils.h"

namespace XNA
{
	class Vector2;

	class SpriteFont
	{
	public:
		std::vector<char> Characters();

		char DefaultCharacter();
		void DefaultCharacter(char);

		i32 LineSpacing();
		void LineSpacing(i32);

		float Spacing();
		void Spacing(float);	

		Vector2 MeasureString(std::string);

	private:
		std::vector<char> _characters;
		char _defaultCharacter;
		i32 _lineSpacing;
		float _spacing;

	};
}


#endif