#include "StaticShader.h"

StaticShader::StaticShader():
	Shader(
		"Resources/shaders/basicShader_v.glsl",
		"Resources/shaders/basicShader_f.glsl"
	)
{
}

StaticShader::~StaticShader()
{
}

void StaticShader::BindAttributes()
{
	BindAttribute(0, "position");
	BindAttribute(1, "textureCoords");
}

void StaticShader::GetAllUniformLocations()
{
	m_location_transformationMatrix = GetUniformLocation("transformationMatrix");
}

void StaticShader::LoadTransformationMatrix(const glm::mat4& _mat) const
{
	Loadmatrix(m_location_transformationMatrix, _mat);
}