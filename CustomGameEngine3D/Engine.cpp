#include "Engine.h"

Engine::Engine():
	m_gameWindow(nullptr),
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
		while (m_gameWindow->IsRunning())
		{
			m_gameWindow->HandleInputs();
			m_gameWindow->Draw();
		}

		m_isEngineRunning = false;
	}
}
