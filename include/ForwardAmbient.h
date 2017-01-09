#ifndef FORWARDAMBIENT_H_INCLUDED
#define FORWARDAMBIENT_H_INCLUDED

#include"Light.h"
#include"shader.h"

class ForwardAmbient : public Shader
{
public:
    ForwardAmbient(const std::string fileName) : Shader(fileName)
    {
        m_uniforms["MaterialAmbientColor"] = glGetUniformLocation(m_program, "MaterialAmbientColor");
    }
    void Update(const Camera&c,const Material& m , RenderingEngine* renderer)
    {
        Shader::Update(c,m ,renderer );
        glm::vec4 color = m.getAmbientColor();
        setUniformVector4f("MaterialAmbientColor" , color.x , color.y ,color.z,color.w);

    }
};

#endif // FORWARDAMBIENT_H_INCLUDED