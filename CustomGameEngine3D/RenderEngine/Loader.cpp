#include "Loader.h"

Loader::Loader()
{
}


Loader::~Loader()
{
	for (auto v_id : m_VAOs)
	{
		glDeleteVertexArrays(1, &v_id);
	}

	for (auto v_id : m_VBOs)
	{
		glDeleteBuffers(1, &v_id);
	}
}

RawModel Loader::LoadToVAO(const std::vector<float>& _positions)
{
	GLuint vaoID = CreateVAO();
	StoreDataInAttributeList(0, _positions);
	UnbindVAO();

	return RawModel(vaoID, _positions.size()/3);
}

GLuint Loader::CreateVAO()
{
	GLuint vaoID;
	glGenVertexArrays(1, &vaoID);

	m_VAOs.push_back(vaoID);

	glBindVertexArray(vaoID);
	return vaoID;
}

void Loader::StoreDataInAttributeList(const int _attribNumber, const std::vector<float>& _data)
{
	GLuint vboID;
	glGenBuffers(1, &vboID);

	m_VBOs.push_back(vboID);

	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	// Add data
	glBufferData(GL_ARRAY_BUFFER, _data.size() * sizeof(_data[0]), &_data[0], GL_STATIC_DRAW);
	// Interpret Data
	glEnableVertexAttribArray(_attribNumber);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	// Unbind buffer
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Loader::UnbindVAO()
{
	glBindVertexArray(0);
}