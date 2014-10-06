#ifndef _IUPDATEABLE_H
#define _IUPDATEABLE_H

namespace XNA
{
	class IUpdateable
	{
	public:
		virtual void Update() = 0;
		virtual ~IUpdateable() = 0;
	};

	inline IUpdateable::~IUpdateable() {}
}


#endif