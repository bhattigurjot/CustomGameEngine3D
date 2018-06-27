#include "StaticShader.h"

StaticShader::StaticShader():
	Shader("Resources/shaders/basicShader_v.glsl", "Resources/shaders/basicShader_f.glsl")
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