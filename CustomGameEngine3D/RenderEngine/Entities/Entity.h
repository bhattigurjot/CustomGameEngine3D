#pragma once

#include <glm/glm.hpp>

#include "../Models/TexturedModel.h"

class Entity
{
public:
	Entity(const TexturedModel _model, const glm::vec3& _pos, const glm::vec3& _rot, const glm::vec3& _scale);
	~Entity();

	// Getters and Setters
	const TexturedModel& GetModel() const;
	void SetModel(const TexturedModel _model);
	glm::vec3 GetPosition() const;
	void SetPosition(const glm::vec3& _pos);
	glm::vec3 GetRotation() const;
	void SetRotation(const glm::vec3& _rot);
	glm::vec3 GetScale() const;
	void SetScale(const glm::vec3& _scale);

	void ChangePosition(const float& _dx, const float& _dy, const float& _dz);
	void ChangeRotation(const float& _dx, const float& _dy, const float& _dz);

private:
	TexturedModel m_model;
	glm::vec3 m_position;
	glm::vec3 m_rotation;
	glm::vec3 m_scale;
};

