#include "Engine.h"

Engine::Engine():
	m_gameWindow(nullptr),
	m_loader(nullptr),
	m_renderer(nullptr),
	m_isEngineRunning(false)
{
	m_gameWindow = new Window(800, 600, "Game Engine Test");
}

Engine::~Engine()
{
	Stop();
	delete m_gameWindow;
}

void Engine::Start()
{
	if (!m_isEngineRunning)
	{
		m_gameWindow->InitializeSystems();
		
		m_renderer = new Renderer();
		m_loader = new Loader();
		m_shader = new StaticShader();

		m_isEngineRunning = true;
	}
}

void Engine::Stop()
{
	if (m_isEngineRunning)
	{
		m_gameWindow->WindowDestroy();
		m_isEngineRunning = false;
	}
}

void Engine::Run()
{
	while (m_isEngineRunning)
	{
		std::vector<float> vertices = {
			-0.5f, 0.5f, 0.0f,
			-0.5f, -0.5f, 0.0f,
			0.5f, -0.5f, 0.0f,
			0.5f, 0.5f, 0.0f
		};
		std::vector<unsigned int> indices = {
			0, 1, 3,
			3, 1, 2
		};

		RawModel model = m_loader->LoadToVAO(vertices, indices);

		while (m_gameWindow->IsRunning())
		{
			m_renderer->Prepare(1.0f, 0.5f, 0.5f, 1.0f);
			
			m_shader->StartShader();
			m_renderer->Render(model);
			m_shader->StopShader();

			m_gameWindow->HandleInputs();
			m_gameWindow->Draw();
		}

		m_isEngineRunning = false;
	}
}