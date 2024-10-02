#include <SDL.h>
#include <iostream>
#include "Clock.h"
#include "Engine.h"

int main(int argc, char* argv[]) {
	Engine* engine = new Engine();
	if (engine->init("Vector2D")) {
		engine->initializeObjects();
		while (engine->isRunning) {
			engine->run();
		}
	} 

	engine->clean();
	delete engine; 

	return 0;
}