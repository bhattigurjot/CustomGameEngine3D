#pragma once

#include "Models/RawModel.h"
//#include "Models/TexturedModel.h"

#include "Utils/EngineMaths.h"
#include "Entities/Entity.h"
#include "Shaders/StaticShader.h"

class Renderer
{
public:
	Renderer();
	~Renderer();

	void Prepare(const float& _r, const float& _g, const float& _b, const float& _a);
	//void Render(const TexturedModel* _model) const;
	void Render(const Entity* _entity, const StaticShader* _shader) const;
};

