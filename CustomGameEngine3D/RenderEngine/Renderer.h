#pragma once

#include "Models/RawModel.h"
//#include "Models/TexturedModel.h"

#include "Utils/EngineMaths.h"
#include "Entities/Entity.h"
#include "Shaders/StaticShader.h"

class Renderer
{
public:
	Renderer(StaticShader* _shader, const float& _aspectRatio);
	~Renderer();

	void Prepare(const float& _r, const float& _g, const float& _b, const float& _a);
	//void Render(const TexturedModel* _model) const;
	void Render(const Entity* _entity, const StaticShader* _shader) const;

private:
	void CreateProjectionMatrix();

	glm::mat4 m_projectionMatrix;

	float m_aspectRatio;

	const float FOV = 70.0f;
	const float NEAR_PLANE = 0.1f;
	const float FAR_PLANE = 1000.0f;
};

