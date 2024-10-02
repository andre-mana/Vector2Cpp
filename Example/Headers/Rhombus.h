#pragma once
#include <SDL.h>
#include "Drawable.h"
#include "Vector2.h"

class Rhombus : public Drawable {
public:
	Rhombus(int x, int y);
	void draw(SDL_Renderer* renderer) override;
	void update()  override;

private: 
	Vector2 perpendicularVector;
	Vector2 target;
	int indexWayPoint;
	SDL_Rect indicatorRect;
	Vector2 indicatorPos;
	static const int MAX_WAYPOINTS = 4; 
	static const int SIDE_LENGTH = 40;
	Vector2 points[MAX_WAYPOINTS];
};

