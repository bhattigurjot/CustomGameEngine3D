#pragma once

#include <SDL/SDL.h>

class Engine;

class EventHandler
{
public:
	EventHandler(Engine* _engine);
	~EventHandler();

	void Handle(SDL_Event* _event);
	void OnQuit();

private:
	Engine* m_engine;
};

