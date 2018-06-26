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

void Renderer::Render(const RawModel& _model)
{
	glBindVertexArray(_model.GetVaoID());
	glEnableVertexAttribArray(0);
	//glDrawArrays(GL_TRIANGLES, 0, _model.GetVertexCount());
	glDrawElements(GL_TRIANGLES, _model.GetVertexCount(), GL_UNSIGNED_INT, 0);
	glDisableVertexAttribArray(0);
	glBindVertexArray(0);
}