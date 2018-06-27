#include "Renderer.h"

Renderer::Renderer(StaticShader* _shader, const float& _aspectRatio):
	m_aspectRatio(_aspectRatio)
{
	CreateProjectionMatrix();

	_shader->StartShader();
	_shader->LoadProjectionMatrix(m_projectionMatrix);
	_shader->StopShader();
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

void Renderer::CreateProjectionMatrix()
{
	//float yScale = (float)((1.0f/glm::tan(glm::radians(FOV/2.0f))) * m_aspectRatio);
	//float xScale = yScale / m_aspectRatio;
	//float frustumLength = FAR_PLANE - NEAR_PLANE;
	//
	//m_projectionMatrix = glm::mat4(1.0);
	//m_projectionMatrix[0][0] = xScale;
	//m_projectionMatrix[1][1] = yScale;
	//m_projectionMatrix[2][2] = -((FAR_PLANE + NEAR_PLANE) / frustumLength);
	//m_projectionMatrix[2][3] = -1;
	//m_projectionMatrix[3][2] = -((2 * FAR_PLANE * NEAR_PLANE) / frustumLength);
	//m_projectionMatrix[3][3] = 0;

	m_projectionMatrix = glm::perspective(
		glm::radians(FOV),
		m_aspectRatio,
		NEAR_PLANE,
		FAR_PLANE
	);
}