#include "Rhombus.h" 
#include "Settings.h"
#include <random> 

Rhombus::Rhombus(int _x, int _y) {
	points[0].x = _x;
	points[0].y = _y;

	points[1].x = points[0].x + 1.2*SIDE_LENGTH;
	points[1].y = points[0].y + 1.2*SIDE_LENGTH;

	points[2].x = points[0].x;
	points[2].y = points[1].y + 1.2*SIDE_LENGTH;

	points[3].x = points[0].x - 1.2*SIDE_LENGTH;
	points[3].y = points[0].y +1.2*SIDE_LENGTH;

	indicatorPos = points[0];
	indicatorRect.x = indicatorPos.x;
	indicatorRect.y = indicatorPos.y;
	indicatorRect.w = 5;
	indicatorRect.h = 5;
	indexWayPoint = 0;
	target = points[0];
} 

void Rhombus::update() {	
	indicatorPos = Vector2::MoveTowards(indicatorPos, target, 0.6f); 
	perpendicularVector = Vector2::PerpendicularClockwise(points[indexWayPoint] - points[indexWayPoint - 1 < 0 ? MAX_WAYPOINTS-1 : indexWayPoint-1]).normalized() * 10 ;
	perpendicularVector = perpendicularVector * 2;

	if (Vector2::Distance(indicatorPos, target) < 1) {
		indexWayPoint = (indexWayPoint + 1) % MAX_WAYPOINTS;
		target = points[indexWayPoint];
	}

	indicatorRect.x = indicatorPos.x;
	indicatorRect.y = indicatorPos.y;
}

void Rhombus::draw(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderDrawLine(renderer, points[0].x, points[0].y, points[1].x, points[1].y);
	SDL_RenderDrawLine(renderer, points[1].x, points[1].y, points[2].x, points[2].y);
	SDL_RenderDrawLine(renderer, points[2].x, points[2].y, points[3].x, points[3].y);
	SDL_RenderDrawLine(renderer, points[3].x, points[3].y, points[0].x, points[0].y);

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderDrawLine(renderer, indicatorPos.x, indicatorPos.y, indicatorPos.x+ perpendicularVector.x, indicatorPos.y+ perpendicularVector.y);
}