#pragma once

#include "Shader.h"

class StaticShader final : public Shader
{
public:
	StaticShader();
	~StaticShader();

	void LoadTransformationMatrix(const glm::mat4& _mat) const;

protected:
	void BindAttributes();
	void GetAllUniformLocations();

private:
	GLint m_location_transformationMatrix;
};

