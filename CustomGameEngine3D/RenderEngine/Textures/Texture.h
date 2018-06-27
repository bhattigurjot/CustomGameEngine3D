#pragma once

#include <string>
#include <GL/glew.h>

class Texture
{
public:
	Texture(const std::string& _fileName);
	~Texture();

	void Bind(unsigned int _unit); // upto 32
	void DeleteTexture(const GLuint& _id);
	GLuint GetTextureID() const;

private:
	GLuint m_textureID;
};

