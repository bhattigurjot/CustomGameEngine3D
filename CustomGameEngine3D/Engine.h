#pragma once
#include "RenderEngine/Window.h"
#include "RenderEngine/Loader.h"
#include "RenderEngine/Renderer.h"
#include "RenderEngine/Models/Vertex.h"
#include "RenderEngine/Models/TexturedModel.h"
#include "RenderEngine/Shaders/StaticShader.h"
#include "RenderEngine/Textures/ModelTexture.h"

class Engine
{
public:
	Engine();
	~Engine();

	void Start();
	void Run();
	void Stop();

private:
	bool m_isEngineRunning;

	Window* m_gameWindow;
	Loader* m_loader;
	Renderer* m_renderer;
	StaticShader* m_shader;
};

