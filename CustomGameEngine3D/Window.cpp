#include "Window.h"

#include "Logger.h"

Window::Window(const int _width, const int _height, const std::string& _title):
	m_windowWidth(_width),
	m_windowHeight(_height),
	m_windowTitle(_title),
	m_isRunning(true),
	m_window(nullptr),
	m_glContext(0)
{
}

Window::~Window()
{
	// Delete context
	if (m_glContext || m_glContext != nullptr)
	{
		SDL_GL_DeleteContext(m_glContext);
	}

	// Destroy the window
	if (m_window != nullptr)
	{
		SDL_DestroyWindow(m_window);
	}

	// Quit SDL
	SDL_Quit();
}

void Window::InitializeSystems()
{
	// Initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) // 0 is success
	{
		LogError("Unable to initialize SDL: ", SDL_GetError());
	}

	// Create a window
	m_window = SDL_CreateWindow(
		m_windowTitle.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		m_windowWidth,
		m_windowHeight,
		SDL_WINDOW_OPENGL
	);

	if (m_window == nullptr)
	{
		LogError("SDL Window could not be created! ", SDL_GetError());
		//Exit();
	}

	// Create OpenGL context
	m_glContext = SDL_GL_CreateContext(m_window);
	if (m_glContext == nullptr)
	{
		LogError("SDL Context could not be created!", SDL_GetError());
		//Exit();
	}

	// Initialize GLEW
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		LogError("Glew could not be initalized:", (const char*)glewGetErrorString(err));
		//Exit();
	}
	SDL_Log("Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));

	// Enable double buffer swapping
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
}

void Window::RunLoop()
{
	while (IsRunning())
	{
		HandleInputs();
		Draw();
	}
}

void Window::HandleInputs()
{
	SDL_Event evt;
	while (SDL_PollEvent(&evt))
	{
		switch (evt.type)
		{
		case SDL_QUIT:
			m_isRunning = false;
			break;
		//case SDL_MOUSEMOTION:
		//	std::cout << evt.motion.x << " " << evt.motion.y << std::endl;
		default:
			break;
		}
	}
}

void Window::Clear(float _r, float _g, float _b, float _a)
{
	// Clear value for depth buffer
	glClearDepth(1.0);
	// Clear the color buffer bit and depth buffer bit
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Set the background color
	glClearColor(_r, _g, _b, _a);
}

void Window::Draw()
{
	// Set the background color to clear
	Clear(0.0f, 1.0f, 0.0f, 1.0f);

	// Draw stuff here
	

	// Swap the buffers for the window
	SDL_GL_SwapWindow(m_window);
}