#include "Shader.h"

Shader::Shader(const std::string& _vertexShaderFile, const std::string& _fragmentShaderFile)
{
	// Create vertex and fragment shader ids
	m_vertexShaderID = LoadShader(_vertexShaderFile, GL_VERTEX_SHADER);
	m_fragmentShaderID = LoadShader(_fragmentShaderFile, GL_FRAGMENT_SHADER);

	// Create program id
	m_programID = glCreateProgram();

	// Add shaders to program
	glAttachShader(m_programID, m_vertexShaderID);
	glAttachShader(m_programID, m_fragmentShaderID);

	// Link Program
	glLinkProgram(m_programID);
	CheckShaderError(m_programID, GL_LINK_STATUS, true, "Error: Program Linking failed");

	// Validate program
	glValidateProgram(m_programID);
	CheckShaderError(m_programID, GL_VALIDATE_STATUS, true, "Error: Program is invalid");

	GetAllUniformLocations();
}

Shader::~Shader()
{
	// Run stop just in case
	StopShader();

	// Detach shaders
	glDetachShader(m_programID, m_vertexShaderID);
	glDetachShader(m_programID, m_fragmentShaderID);

	// Delete shaders
	glDeleteShader(m_vertexShaderID);
	glDeleteShader(m_fragmentShaderID);

	// Delete program
	glDeleteProgram(m_programID);
}

void Shader::StartShader()
{
	glUseProgram(m_programID);
}

void Shader::StopShader()
{
	glUseProgram(0);
}

void Shader::BindAttribute(const GLuint _attribute, const GLchar* _variable)
{
	glBindAttribLocation(m_programID, _attribute, _variable);
}

GLint Shader::GetUniformLocation(const std::string& _uniformName)
{
	return glGetUniformLocation(m_programID, _uniformName.c_str());
}

void Shader::LoadFloat(const GLint& _location, const GLfloat& _value) const
{
	glUniform1f(_location, _value);
}

void Shader::LoadBoolean(const GLint& _location, const GLboolean& _value) const
{
	GLboolean toLoad = 0;

	if (_value)
		toLoad = 1;

	glUniform1f(_location, toLoad);
}

void Shader::LoadVector(const GLint& _location, const glm::vec3& _vec) const
{
	glUniform3f(_location, _vec.x, _vec.y, _vec.z);
}

void Shader::Loadmatrix(const GLint& _location, const glm::mat4& _mat) const
{
	glUniformMatrix4fv(_location, _mat.length(), GL_FALSE, glm::value_ptr(_mat));
}

GLuint Shader::LoadShader(const std::string& _fileName, GLenum _shaderType)
{
	std::string shaderText = ReadShaderFile(_fileName);

	GLuint shader = glCreateShader(_shaderType);

	if (shader == 0)
		std::cerr << "Error: Shader creation failed!" << std::endl;

	const GLchar* shaderSourceStrings[1];
	GLint shaderSourceStringsLengths[1];

	shaderSourceStrings[0] = shaderText.c_str();
	shaderSourceStringsLengths[0] = shaderText.length();

	glShaderSource(shader, 1, shaderSourceStrings, shaderSourceStringsLengths);
	glCompileShader(shader);

	CheckShaderError(shader, GL_COMPILE_STATUS, false, "Error: Shader compilation failed");

	return shader;
}

std::string Shader::ReadShaderFile(const std::string& _fileName)
{
	std::ifstream file;
	file.open((_fileName).c_str());

	std::string line;
	std::string output;

	if (file.is_open())
	{
		while (file.good())
		{
			getline(file, line);
			output.append(line + "\n");
		}

		file.close();
	}
	else
	{
		std::cerr << "Unable to load shader: " << _fileName << std::endl;
	}

	return output;
}

void Shader::CheckShaderError(GLuint _shader, GLuint _flag, bool _isProgram, const std::string& _errorMessage)
{
	GLint success = 0;
	GLchar error[1024] = { 0 };

	if (_isProgram)
		glGetProgramiv(_shader, _flag, &success);
	else
		glGetShaderiv(_shader, _flag, &success);

	if (success == GL_FALSE)
	{
		if (_isProgram)
			glGetProgramInfoLog(_shader, sizeof(error), NULL, error);
		else
			glGetShaderInfoLog(_shader, sizeof(error), NULL, error);

		std::cerr << _errorMessage << ": '" << error << "'" << std::endl;
	}

}