#include "Entity.h"

Entity::Entity(const TexturedModel _model, const glm::vec3& _pos, const glm::vec3& _rot, const glm::vec3& _scale):
	m_model(_model),
	m_position(_pos),
	m_rotation(_rot),
	m_scale(_scale)
{
}

Entity::~Entity()
{
}

void Entity::ChangePosition(const float& _dx, const float& _dy, const float& _dz)
{
	m_position.x += _dx;
	m_position.y += _dy;
	m_position.z += _dz;
}

void Entity::ChangeRotation(const float& _dx, const float& _dy, const float& _dz)
{
	m_rotation.x += _dx;
	m_rotation.y += _dy;
	m_rotation.z += _dz;
}

const TexturedModel& Entity::GetModel() const
{
	return m_model;
}

void Entity::SetModel(const TexturedModel _model)
{
	m_model = _model;
}

glm::vec3 Entity::GetPosition() const
{
	return m_position;
}

void Entity::SetPosition(const glm::vec3& _pos)
{
	m_position = _pos;
}

glm::vec3 Entity::GetRotation() const
{
	return m_rotation;
}

void Entity::SetRotation(const glm::vec3& _rot)
{
	m_rotation = _rot;
}

glm::vec3 Entity::GetScale() const
{
	return m_scale;
}

void Entity::SetScale(const glm::vec3& _scale)
{
	m_scale = _scale;
}