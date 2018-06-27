#pragma once

#include <GL/glew.h>

class ModelTexture
{
public:
	ModelTexture(const GLuint& _id);
	~ModelTexture();

	GLuint GetTextureID() const;

private:
	GLuint m_textureID;
};