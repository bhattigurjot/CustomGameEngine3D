#pragma once

#include <glm/glm.hpp>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/transform.hpp>

class EngineMaths
{
public:
	static glm::mat4 CreateTransformationMatrix(const glm::vec3& _translation, const glm::vec3& _rotation, const glm::vec3& _scale)
	{
		glm::mat4 matrix = glm::mat4(1.0);
		matrix = glm::translate(matrix, _translation);
		matrix = glm::rotate(matrix, glm::radians(_rotation.x), glm::vec3(1.0, 0.0, 0.0));
		matrix = glm::rotate(matrix, glm::radians(_rotation.y), glm::vec3(0.0, 1.0, 0.0));
		matrix = glm::rotate(matrix, glm::radians(_rotation.z), glm::vec3(0.0, 0.0, 1.0));
		matrix = glm::scale(matrix, _scale);

		return matrix;
	}
};

