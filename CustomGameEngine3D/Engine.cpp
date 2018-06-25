#include "Engine.h"

Engine::Engine():
	m_window(nullptr)
{
	m_window = new Window(800, 600, "Game Engine Test");
}

Engine::~Engine()
{
}

void Engine::Run()
{
	m_window->InitializeSystems();
	m_window->RunLoop();
}
