#include "Texture.h"
#include "../Utils/Logger.h"
#define STB_IMAGE_IMPLEMENTATION
#include "../Utils/stb_image.h"

Texture::Texture(const std::string& _fileName)
{
	int width, height, numComponents;
	// load image texture
	unsigned char* imageData = stbi_load(_fileName.c_str(), &width, &height, &numComponents, 4);

	if (imageData == nullptr)
		LogError("Failed to load image texture: " + _fileName);

	// Generate texture and bind
	glGenTextures(1, &m_textureID);
	glBindTexture(GL_TEXTURE_2D, m_textureID);

	// Set parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // wrao
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); // wrap
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // interpolate
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // interpolate

	// Send Image to GPU
	glTexImage2D(
		GL_TEXTURE_2D,
		0,
		GL_RGBA,
		width,
		height,
		0,
		GL_RGBA,
		GL_UNSIGNED_BYTE,
		imageData
	);

	// free image data
	stbi_image_free(imageData);
}


Texture::~Texture()
{
	//DeleteTexture(m_textureID);
}

void Texture::DeleteTexture(const GLuint& _id)
{
	glDeleteTextures(1, &_id);
}

void Texture::Bind(unsigned int _unit)
{
	assert(_unit >= 0 && _unit <= 31);

	glActiveTexture(GL_TEXTURE0 + _unit); // makes it easy to bind to unit
	glBindTexture(GL_TEXTURE_2D, m_textureID);
}

GLuint Texture::GetTextureID() const
{
	return m_textureID;
}