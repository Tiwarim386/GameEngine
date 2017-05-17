#ifndef SKYBOXSHADER_H_INCLUDED
#define SKYBOXSHADER_H_INCLUDED

#include"Light.h"
#include"shader.h"
#include"string"
#include <glm/gtc/type_ptr.hpp>

class SkyBoxShader : public Shader
{
public:
    SkyBoxShader(const std::string fileName) : Shader(fileName , false)
    {
        m_uniforms["projection"] = glGetUniformLocation(m_program , "projection");
    }
    void UpdateSkyBox(const Camera&c)
    {
        glm::mat4 proj = c.getProjection();
        glm::mat4 view = glm::mat4_cast(glm::conjugate(c.getRot()));
       // glm::mat4 view = glm::mat4(glm::mat3(c.getModel()));
        setUniformMatrix4f("projection" , &proj[0][0]);
        setUniformMatrix4f("Model" , &view[0][0]);
    }
};


#endif // SKYBOXSHADER_H_INCLUDED
