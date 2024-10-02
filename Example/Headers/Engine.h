#pragma once 
#include <SDL.h>
#include <vector> 
#include "Drawable.h"

class Engine {
public: 
	~Engine(); 

	bool init(const char* title);
	void initializeObjects();
	void handleEvents();  
	void update();
	void draw();
	void clean();
	void run(); 
	bool isRunning;
	std::vector<Drawable *> drawables;

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event event; 
};
 