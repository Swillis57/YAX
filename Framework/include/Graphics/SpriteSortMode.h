#ifndef _SPRITE_SORT_MODE_H
#define _SPRITE_SORT_MODE_H

namespace XNA
{
	enum class SpriteSortMode : int 
	{
		BackToFront,
		Deferred,
		FrontToBack,
		Immediate,
		Texture
	};
}


#endif