#pragma once

#include <GL/glew.h>

class RawModel
{
public:
	RawModel(GLuint _vaoID, int _vertexCount);
	~RawModel();

	GLuint GetVaoID() const;
	int GetVertexCount() const;

private:
	GLuint m_vaoID;
	int m_vertexCount;
};