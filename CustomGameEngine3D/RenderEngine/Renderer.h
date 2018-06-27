#pragma once

#include "Models/RawModel.h"
#include "Models/TexturedModel.h"

class Renderer
{
public:
	Renderer();
	~Renderer();

	void Prepare(const float& _r, const float& _g, const float& _b, const float& _a);
	void Render(const TexturedModel* _model) const;
};

