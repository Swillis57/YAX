#include "../../include/Graphics/Effect.h"

#include <exception>
#include "../../include/Graphics/Texture.h"

namespace YAX
{
    Effect::Effect(const std::string& vert, const std::string& frag)
        : GraphicsResource(""),
        _texUnitCounter(0)
    {
        _id = glCreateProgram();
        GLuint vs = CreateShader(vert, GL_VERTEX_SHADER);
        GLuint fs = CreateShader(frag, GL_FRAGMENT_SHADER);
        
        glAttachShader(_id, vs);
        glAttachShader(_id, fs);
        glLinkProgram(_id);

        GLint err = 0;
        glGetProgramiv(_id, GL_LINK_STATUS, &err);
        if (err == GL_FALSE)
        {
            GLint logLen = 0;
            glGetProgramiv(_id, GL_INFO_LOG_LENGTH, &logLen);
            std::string message { "Error linking shader program: " };
            char* log = new char[logLen];
            glGetProgramInfoLog(_id, logLen, &logLen, log);
            message.append(log);

            delete[] log;
            glDetachShader(_id, vs);
            glDeleteShader(vs);
            glDetachShader(_id, fs);
            glDeleteShader(fs);
            glDeleteProgram(_id);
            throw std::runtime_error(message);
        }

        glDetachShader(_id, vs);
        glDetachShader(_id, fs);
        glDeleteShader(vs);
        glDeleteShader(fs);

    }

    Effect::~Effect()
    {
        glDeleteProgram(_id);
        glUseProgram(0);
    }

    Effect::Effect(Effect&& old)
        : GraphicsResource(std::move(old)),
        Parameters(std::move(old.Parameters)),
        _id(old._id)
    {
        old._id = 0;
    }

    Effect& Effect::operator=(Effect&& old)
    {
        GraphicsResource::operator=(std::move(old));
        this->_id = old._id;
        this->Parameters = std::move(old.Parameters);

        old._id = 0;

        return *this;
    }

    void Effect::Apply() const
    {
        //Tell OpenGL to use this Effect's shader and link any textures to
        //their requested texture units
        glUseProgram(_id);
        for (auto& kv : Parameters)
        {
            auto& currP = kv.second;

            //If _tex isn't null, then the parameter represents a texture
            if (currP._tex)
                currP._tex->Bind(currP._texUnit);
        }
    }
    
    std::string Effect::Name() const
    {
        return _name;
    }

    GLuint Effect::CreateShader(const std::string& source, GLenum type)
    {
        GLuint id = glCreateShader(type);
        GLint len = source.size();
        const char* src = source.c_str();
        glShaderSource(id, 1, &src, &len);
        glCompileShader(id);

        GLint err = 0;
        glGetShaderiv(id, GL_COMPILE_STATUS, &err);
        if (err == GL_FALSE)
        {
            GLint logLen = 0;
            glGetShaderiv(id, GL_INFO_LOG_LENGTH, &logLen);
            std::string message { "Error creating shader: " };
            char* log = new char[logLen];
            glGetShaderInfoLog(id, logLen, &logLen, log);
            message.append(log);
            
            delete[] log;
            glDeleteShader(id);
            throw std::runtime_error(message);
        }

        return id;
    }
}