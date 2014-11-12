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
		const std::vector<char>& Characters() const;

		char DefaultCharacter() const;
		void DefaultCharacter(char);

		i32 LineSpacing() const;
		void LineSpacing(i32);

		float Spacing() const;
		void Spacing(float);	

		Vector2 MeasureString(std::string) const;

	private:
		//FT_Face _face; //For FreeType (NYI)
		std::vector<char> _characters;
		char _defaultCharacter;
		i32 _lineSpacing;
		float _spacing;

	};
}


#endif