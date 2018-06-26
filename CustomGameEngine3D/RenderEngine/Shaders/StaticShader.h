#pragma once

#include "Shader.h"

class StaticShader final : public Shader
{
public:
	StaticShader();
	~StaticShader();

protected:
	void BindAttributes();
};

