#pragma once
#include <SDL.h>

class Drawable {
public:
	virtual ~Drawable() = default;
	virtual void draw(SDL_Renderer* renderer) = 0;
	virtual void update() = 0;
};