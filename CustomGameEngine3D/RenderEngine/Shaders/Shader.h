#pragma once

#include <string>
#include <fstream>
#include <iostream>

#include <GL/glew.h>

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

private:
	GLuint LoadShader(const std::string& _fileName, GLenum _shaderType);
	std::string ReadShaderFile(const std::string& _fileName);
	void CheckShaderError(GLuint _shader, GLuint _flag, bool _isProgram, const std::string& _errorMessage);

	GLuint m_programID;
	GLuint m_vertexShaderID;
	GLuint m_fragmentShaderID;
};

