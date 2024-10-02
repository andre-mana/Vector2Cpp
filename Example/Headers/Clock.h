#pragma once
#include <SDL.h>
#include "Drawable.h"
#include "Vector2.h"

class Clock : public Drawable {
public:
	Clock(int x, int y, SDL_Renderer* renderer);
	void draw(SDL_Renderer* renderer) override;
	void update()  override;

private:
	Vector2 initialPos;
	float theta;
	Vector2 minutHandDirection;
	Vector2 hourHandDirection;
	float lengthMinutHand;
	float lengthHourHand;
	float arcAngle;
	Vector2 arc;
	SDL_Surface* textSurface;
	SDL_Texture* textTexture;
};