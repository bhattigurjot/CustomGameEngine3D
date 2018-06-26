#pragma once

#include "Models/RawModel.h"

class Renderer
{
public:
	Renderer();
	~Renderer();

	void Prepare(const float& _r, const float& _g, const float& _b, const float& _a);
	void Render(const RawModel& _model);
};

