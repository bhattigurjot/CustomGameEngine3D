#include "ModelTexture.h"

ModelTexture::ModelTexture(const GLuint& _id) :
	m_textureID(_id)
{

}

ModelTexture::~ModelTexture()
{

}

GLuint ModelTexture::GetTextureID() const
{
	return m_textureID;
}