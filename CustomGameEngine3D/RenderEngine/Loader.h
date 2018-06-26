#pragma once

#include "Models/RawModel.h"

#include <vector>

class Loader
{
public:
	Loader();
	~Loader();

	RawModel LoadToVAO(const std::vector<float>& _positions, const std::vector<unsigned int>& _indices);

private:
	GLuint CreateVAO();
	void StoreDataInAttributeList(const int _attribNumber, const std::vector<float>& _data);
	void BindIndicesBuffer(const std::vector<unsigned int>& _indices);
	void UnbindVAO();

	std::vector<GLuint> m_VAOs;
	std::vector<GLuint> m_VBOs;
};

