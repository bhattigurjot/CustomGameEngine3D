#pragma once

#include <GL/glew.h>

class RawModel
{
public:
	RawModel(const GLuint _vaoID, const int _vertexCount);
	~RawModel();

	GLuint GetVaoID() const;
	int GetVertexCount() const;

private:
	GLuint m_vaoID;
	int m_vertexCount;
};