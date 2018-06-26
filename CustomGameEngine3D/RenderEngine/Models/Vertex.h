#pragma once

#include <glm/glm.hpp>

class Vertex
{
public:
	Vertex(const glm::vec3& _pos) :
		m_pos(_pos)
	{

	}
	~Vertex() {}

	glm::vec3* GetPosition() { return &m_pos; }

private:
	glm::vec3 m_pos;
};