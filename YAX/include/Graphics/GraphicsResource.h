#ifndef _GRAPHICS_RESOURCE_H
#define _GRAPHICS_RESOURCE_H

#include <string>

namespace YAX
{
    class GraphicsResource
    {
    public:
        GraphicsResource(std::string);
        
        GraphicsResource(const GraphicsResource& old)
            : _name(old._name)
        {}

        virtual ~GraphicsResource() = default;

        GraphicsResource& operator=(const GraphicsResource& old)
        {
            this->_name = old._name;
            
            return *this;
        }

        GraphicsResource(GraphicsResource&& old)
            : _name(old._name) 
        {}

        GraphicsResource& operator=(GraphicsResource&& old)
        {
            this->_name = old._name;
            return *this;
        }

        std::string Name();
        void Name(std::string s) { _name = s; }
    
    protected:
        std::string _name;
    };
}


#endif