#ifndef _IDRAWABLE_H
#define _IDRAWABLE_H

namespace YAX
{
	class IDrawable
	{
	public:
		virtual void Draw() = 0;
		virtual ~IDrawable() = default;
	};
}


#endif