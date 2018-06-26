#pragma once

#include "RawModel.h"

#include <vector>

class Loader
{
public:
	Loader();
	~Loader();

	RawModel LoadToVAO(const std::vector<float>& _positions);

private:
	GLuint CreateVAO();
	void StoreDataInAttributeList(const int _attribNumber, const std::vector<float>& _data);
	void UnbindVAO();

	std::vector<GLuint> m_VAOs;
	std::vector<GLuint> m_VBOs;
};

