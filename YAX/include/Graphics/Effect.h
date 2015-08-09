#ifndef _EFFECT_H
#define _EFFECT_H

#include <string>
#include "EffectParameterCollection.h"
#include "../../../external/glew/include/GL/glew.h"
#include "../Utils.h"

namespace YAX
{
    class GraphicsDevice;

    class Effect
    {
    public:
        EffectParameterCollection Parameters;
        
        Effect(GraphicsDevice&, const std::string& vert, const std::string& frag);
        Effect(const Effect&) = delete;
        Effect& operator=(const Effect&) = delete;
        Effect(Effect&&);
        Effect& operator=(Effect&&);
        ~Effect();

        void Apply() const;
        std::string Name() const;

    protected:
        GLuint CreateShader(const std::string&, GLenum);

        std::string _name;
        GLuint _id;
        GraphicsDevice* _device;
    };
}


#endif
