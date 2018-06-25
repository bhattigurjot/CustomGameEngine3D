#include <iostream>

#include "Engine.h"

int main(int argc, char**argv)
{
	Engine engine;

	engine.Start();
	engine.Run();
	engine.Stop();

	return 0;
}