#pragma once

#include <iostream>
#include <string>

static void LogError(const std::string& _errorMessage, const char* _sdlError)
{
	std::cerr << "Error: " << _errorMessage << _sdlError << std::endl;
}