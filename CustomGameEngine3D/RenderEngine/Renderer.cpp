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

void Renderer::Render(const TexturedModel* _model) const
{
	const RawModel& rawModel = _model->GetRawModel();

	glBindVertexArray(rawModel.GetVaoID());
	
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glActiveTexture(GL_TEXTURE0);

	glBindTexture(GL_TEXTURE_2D, _model->GetTexture().GetTextureID());
	glDrawElements(GL_TRIANGLES, rawModel.GetVertexCount(), GL_UNSIGNED_INT, 0);
	
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	
	glBindVertexArray(0);
}