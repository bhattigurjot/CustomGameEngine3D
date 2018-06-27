#pragma once

#include <string>
#include <fstream>
#include <iostream>

#include <GL/glew.h>
#include <glm/glm.hpp>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtc/type_ptr.hpp>

class Shader
{
public:
	Shader(const std::string& _vertexShaderFile, const std::string& _fragmentShaderFile);
	~Shader();

	void StartShader();
	void StopShader();

protected:
	virtual void BindAttributes() = 0;
	void BindAttribute(const GLuint _attribute, const GLchar* _variable);

	virtual void GetAllUniformLocations() = 0;
	GLint GetUniformLocation(const GLchar* _uniformName);

	void LoadFloat(const GLint& _location, const GLfloat& _value) const;
	void LoadBoolean(const GLint& _location, const GLboolean& _value) const;
	void LoadVector(const GLint& _location, const glm::vec3& _vec) const;
	void LoadMatrix(const GLint& _location, const glm::mat4& _mat) const;

private:
	GLuint LoadShader(const std::string& _fileName, GLenum _shaderType);
	std::string ReadShaderFile(const std::string& _fileName);
	void CheckShaderError(GLuint _shader, GLuint _flag, bool _isProgram, const std::string& _errorMessage);

	GLuint m_programID;
	GLuint m_vertexShaderID;
	GLuint m_fragmentShaderID;
};

