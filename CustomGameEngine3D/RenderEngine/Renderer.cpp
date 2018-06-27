#include "Renderer.h"

Renderer::Renderer()
{
}


Renderer::~Renderer()
{
}

void Renderer::Prepare(const float& _r, const float& _g, const float& _b, const float& _a)
{
	glClearColor(_r, _g, _b, _a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

//void Renderer::Render(const TexturedModel* texturedModel) const
void Renderer::Render(const Entity* _entity, const StaticShader* _shader) const
{
	const TexturedModel& texturedModel = _entity->GetModel();
	const RawModel& rawModel = texturedModel.GetRawModel();

	glBindVertexArray(rawModel.GetVaoID());
	
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glm::mat4 transformationMatrix = EngineMaths::CreateTransformationMatrix(_entity->GetPosition(), _entity->GetRotation(), _entity->GetScale());
	_shader->LoadTransformationMatrix(transformationMatrix);

	glActiveTexture(GL_TEXTURE0);

	glBindTexture(GL_TEXTURE_2D, texturedModel.GetTexture().GetTextureID());
	glDrawElements(GL_TRIANGLES, rawModel.GetVertexCount(), GL_UNSIGNED_INT, 0);
	
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	
	glBindVertexArray(0);
}