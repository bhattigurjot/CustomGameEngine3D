#include "StaticShader.h"

StaticShader::StaticShader():
	Shader(
		"Resources/shaders/basicShader_v.glsl",
		"Resources/shaders/basicShader_f.glsl"
	)
{
	// Calling from here
	GetAllUniformLocations();
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
	m_location_projectionMatrix = GetUniformLocation("projectionMatrix");
}

void StaticShader::LoadTransformationMatrix(const glm::mat4& _mat) const
{
	LoadMatrix(m_location_transformationMatrix, _mat);
}

void StaticShader::LoadProjectionMatrix(const glm::mat4& _mat) const
{
	LoadMatrix(m_location_projectionMatrix, _mat);
}