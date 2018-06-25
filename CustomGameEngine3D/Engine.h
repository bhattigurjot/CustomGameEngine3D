#pragma once
#include "Window.h"

class Engine
{
public:
	Engine();
	~Engine();

	void Run();

private:
	Window* m_window;
};

