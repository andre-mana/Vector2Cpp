#include <iostream>
#include <SDL.h> 
#include "Engine.h"
#include "Settings.h"
#include "Clock.h"
#include "Mirror.h"
#include "ProgressLine.h"
#include "Rhombus.h"
#include "Shadow.h"

Engine::~Engine() {
	clean();
}

bool Engine::init(const char* title) {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
		return false;
	}

	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (!window) {
		std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!renderer) {
		std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
		return false;
	}

	isRunning = true;
	SDL_ShowCursor(SDL_DISABLE);

	return true;
}

void Engine::handleEvents() {
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			isRunning = false;
		}
	}
}

void Engine::initializeObjects() {
	Clock* clock = new Clock(80, 100,renderer);
	Rhombus* rhombus = new Rhombus(400, 70);
	ProgressLine* progressLine = new ProgressLine(200, 250, 90);
	Mirror* mirror = new Mirror(50, 400, Vector2(1, 1), 80);
	Shadow* shadow = new Shadow(360, 400);
	drawables.push_back(clock);
	drawables.push_back(rhombus);
	drawables.push_back(progressLine);
	drawables.push_back(mirror);
	drawables.push_back(shadow);	 
}

void Engine::update() {
	for (const auto& drawable : drawables) {
		drawable->update();
	}
}

void Engine::draw() {

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

	SDL_RenderClear(renderer);
	for (const auto& drawable : drawables) {
		drawable->draw(renderer);
	} 

	SDL_RenderPresent(renderer); 
}

void Engine::clean() {
	SDL_DestroyRenderer(renderer); 
	SDL_DestroyWindow(window);  
	SDL_Quit();
}

void Engine::run() {
	update();
	handleEvents();
	draw();
}