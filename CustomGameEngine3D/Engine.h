#pragma once
#include "Window.h"

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
};

