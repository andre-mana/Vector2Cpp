#pragma once
#include <SDL.h>
#include "Drawable.h"
#include "Vector2.h"

class ProgressLine : public Drawable {
public:
	ProgressLine(int x, int y,int length);
	void draw(SDL_Renderer* renderer) override;
	void update()  override; 

private:
	SDL_Rect indicatorRect;
	Vector2 indicatorPos;
	Vector2 origin;
	int lineLength;

	static const int MAX_WAYPOINTS = 2;
	Vector2 wayPoints[MAX_WAYPOINTS];
	Vector2 target;
	int indexWayPoint = 0;
};

