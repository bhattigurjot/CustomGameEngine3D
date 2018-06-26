#include "Loader.h"

Loader::Loader()
{
}


Loader::~Loader()
{
	// Delete all VAOs
	for (auto v_id : m_VAOs)
	{
		glDeleteVertexArrays(1, &v_id);
	}
	// Delete all VBOs
	for (auto v_id : m_VBOs)
	{
		glDeleteBuffers(1, &v_id);
	}
}

RawModel Loader::LoadToVAO(const std::vector<float>& _positions, const std::vector<unsigned int>& _indices)
{
	GLuint vaoID = CreateVAO();
	BindIndicesBuffer(_indices);
	StoreDataInAttributeList(0, _positions);
	UnbindVAO();

	return RawModel(vaoID, _indices.size());
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

void Loader::BindIndicesBuffer(const std::vector<unsigned int>& _indices)
{
	GLuint vboID;
	glGenBuffers(1, &vboID);

	m_VBOs.push_back(vboID);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboID);
	// Add data
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, _indices.size() * sizeof(_indices[0]), &_indices[0], GL_STATIC_DRAW);
	//// Interpret Data
	//glEnableVertexAttribArray(_attribNumber);
	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	// Unbind buffer
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Loader::UnbindVAO()
{
	glBindVertexArray(0);
}