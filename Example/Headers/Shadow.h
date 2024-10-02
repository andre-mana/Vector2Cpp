#pragma once
#include <SDL.h>
#include "Drawable.h"
#include "Vector2.h"

class Shadow : public Drawable {
public:
	Shadow(int x, int y);
	void draw(SDL_Renderer* renderer) override;
	void update()  override;

private: 
	Vector2 initialPos;
	float theta;
	Vector2 minutHandDirection;
	Vector2 hourHandDirection;
	float lengthMinutHand;
	float lengthHourHand; 
	Vector2 projectedVector;
	Vector2 pointToBeProjected;
	Vector2 projectedPoint;
	Vector2 orthogonal;
};

