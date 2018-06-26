#include "EventHandler.h"

EventHandler::EventHandler(Engine* _engine):
	m_engine(_engine)
{
}


EventHandler::~EventHandler()
{
}

void EventHandler::Handle(SDL_Event* _event)
{
	switch (_event->type)
	{
	case SDL_QUIT:
		OnQuit();
		break;
	default:
		break;
	}
}

void EventHandler::OnQuit()
{
	SDL_Quit();
}