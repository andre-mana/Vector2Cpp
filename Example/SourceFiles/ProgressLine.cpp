#include "ProgressLine.h" 
#include "Settings.h"

ProgressLine::ProgressLine(int _x, int _y, int _lineLength) {
	origin.x = _x;
	origin.y = _y;
	lineLength = _lineLength;

	indicatorPos.x = origin.x;
	indicatorPos.y = origin.y;
	indicatorRect.x = indicatorPos.x;
	indicatorRect.y = indicatorPos.y;
	indicatorRect.w = 5;
	indicatorRect.h = 5;

	indexWayPoint = 0;
	wayPoints[0] = Vector2(origin.x + lineLength, origin.y);
	wayPoints[1] = Vector2(origin.x, origin.y);
	target = wayPoints[0];
}

void ProgressLine::update() {

	indicatorPos = Vector2::Lerp(indicatorPos, target, 0.05f); 

	if (Vector2::Distance(indicatorPos, target) < 1) { 
		indexWayPoint = (indexWayPoint + 1) % MAX_WAYPOINTS;
		target = wayPoints[indexWayPoint];
	} 

	indicatorRect.x = indicatorPos.x;
	indicatorRect.y = indicatorPos.y;
}

void ProgressLine::draw(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderDrawLine(renderer, origin.x, origin.y, origin.x+lineLength, origin.y);

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); 
	SDL_RenderDrawLine(renderer, origin.x, origin.y, indicatorPos.x, origin.y);
}