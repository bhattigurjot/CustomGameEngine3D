#include "RawModel.h"

RawModel::RawModel(const GLuint _vaoID, const int _vertexCount):
	m_vaoID(_vaoID),
	m_vertexCount(_vertexCount)
{

}

RawModel::~RawModel()
{

}

GLuint RawModel::GetVaoID() const 
{ 
	return m_vaoID;
}

int RawModel::GetVertexCount() const 
{ 
	return m_vertexCount;
}