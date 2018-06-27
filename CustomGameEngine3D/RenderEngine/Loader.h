#pragma once

#include "Models/RawModel.h"
#include "Textures/Texture.h"

#include <vector>

class Loader
{
public:
	Loader();
	~Loader();

	RawModel LoadToVAO(const std::vector<float>& _positions, const std::vector<float>& _textureCoords, const std::vector<unsigned int>& _indices);
	RawModel LoadToVAO(const std::vector<float>& _positions, int dimensions);
	GLuint LoadTexture(const std::string& _fileName);

private:
	GLuint CreateVAO();
	void StoreDataInAttributeList(const int _attribNumber, const int _coordinates, const std::vector<float>& _data);
	void BindIndicesBuffer(const std::vector<unsigned int>& _indices);
	void UnbindVAO();

	std::vector<GLuint> m_VAOs;
	std::vector<GLuint> m_VBOs;
	std::vector<GLuint> m_TEXTUREs;
};

