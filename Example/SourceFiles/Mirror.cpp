#include "Mirror.h" 
#include "Settings.h"

Mirror::Mirror(int _x, int _y, Vector2 _direction, int _length) {
	x = _x;
	y = _y;
	mirrorDirection = _direction.normalized();
	mirrorLength = _length;

	emissionPoint.x = x;
	emissionPoint.y = y-30;
	 
	midlePointMirror.x = x + mirrorDirection.x * mirrorLength / 2;
	midlePointMirror.y = y + mirrorDirection.y * mirrorLength / 2;

	reflectedLength = Vector2::Distance(emissionPoint,midlePointMirror);
	mirrorNormal = Vector2::PerpendicularClockwise(mirrorDirection);
	emissionDirection = (emissionPoint - midlePointMirror).normalized();
	reflectedDirection = Vector2::Reflect(emissionDirection, mirrorDirection);
	reflectedPoint = midlePointMirror + reflectedDirection * reflectedLength;
}

void Mirror::update() {}

void Mirror::draw(SDL_Renderer* renderer) {
	//mirror
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderDrawLine(renderer, x, y, x + mirrorDirection.x * mirrorLength, y + mirrorDirection.y * mirrorLength);

	//normal
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderDrawLine(renderer, midlePointMirror.x, midlePointMirror.y, midlePointMirror.x + mirrorNormal.x * 20, midlePointMirror.y + mirrorNormal.y * 20);

	//reflection
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	SDL_RenderDrawLine(renderer, reflectedPoint.x, reflectedPoint.y, midlePointMirror.x, midlePointMirror.y);

	//emission
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	SDL_RenderDrawLine(renderer, emissionPoint.x, emissionPoint.y, midlePointMirror.x, midlePointMirror.y);
}