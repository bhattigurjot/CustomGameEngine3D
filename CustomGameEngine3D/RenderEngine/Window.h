#pragma once

#include <string>

#include <SDL/SDL.h>
#include <GL/glew.h>

class Window
{
public:
	Window(const int _width, const int _height, const std::string& _title);
	~Window();

	int GetWindowHeight() const;
	int GetWindowWidth() const;
	float GetAspectRatio() const;
	bool IsRunning() const;

	void WindowDestroy();
	void InitializeSystems();
	void HandleInputs();
	void Clear(float _r, float _g, float _b, float _a);
	void Draw();

private:
	int m_windowWidth;
	int m_windowHeight;
	std::string m_windowTitle;
	bool m_isRunning;

	SDL_Window* m_window;
	SDL_GLContext m_glContext;
};

