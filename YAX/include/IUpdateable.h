#ifndef _IUPDATEABLE_H
#define _IUPDATEABLE_H

namespace YAX
{
	class IUpdateable
	{
	public:
		virtual void Update() = 0;
		virtual ~IUpdateable() = default;
	};
}


#endif