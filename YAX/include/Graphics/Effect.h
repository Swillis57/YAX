#ifndef _EFFECT_H
#define _EFFECT_H

#include <string>
#include "EffectParameterCollection.h"
#include "../../../external/glew/include/GL/glew.h"
#include "GraphicsResource.h"
#include "../Utils.h"

namespace YAX
{
    class Effect : public GraphicsResource
    {
    public:
        EffectParameterCollection Parameters;
        
        Effect(const std::string&, const std::string&);
        Effect(const Effect&) = delete;
        Effect& operator=(const Effect&) = delete;
        Effect(Effect&&);
        Effect& operator=(Effect&&);
        ~Effect();

        void Apply() const;
        std::string Name() const;
        ui32 RequestTextureUnit();

    protected:
        GLuint CreateShader(const std::string&, GLenum);

        std::string _name;
        GLuint _id;
        ui32 _texUnitCounter;
    };
}


#endif
