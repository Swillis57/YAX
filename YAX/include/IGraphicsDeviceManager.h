#ifndef _GDM_INTERFACE
#define _GDM_INTERFACE

#include "IGameService.h"

namespace YAX
{
    class IGraphicsDeviceManager : public IGameService
    {
    public:
        virtual bool BeginDraw() = 0;
        virtual void CreateDevice() = 0;
        virtual void EndDraw() = 0;
        virtual ~IGraphicsDeviceManager() = default;

    protected:
        bool _drawing;
    };
}
#endif