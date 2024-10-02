#include "Shadow.h" 
#include "Settings.h"

Shadow::Shadow(int x, int y) {
	hourHandDirection = Vector2::right;
	minutHandDirection = Vector2(1,1);
	initialPos.x = x;
	initialPos.y = y;
	theta = 0.01;
	lengthHourHand = 60;
	lengthMinutHand = 60;
}

void Shadow::update() {
	hourHandDirection.RotatedRadians(theta);
	minutHandDirection.RotatedRadians(theta / 15);
	projectedVector = Vector2::Project(hourHandDirection * lengthHourHand, minutHandDirection * lengthMinutHand);
	pointToBeProjected = initialPos + hourHandDirection * lengthHourHand;
	projectedPoint = initialPos + projectedVector;
}

void Shadow::draw(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderDrawLine(renderer, initialPos.x, initialPos.y, initialPos.x + minutHandDirection.x * lengthMinutHand, initialPos.y + minutHandDirection.y * lengthMinutHand);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderDrawLine(renderer, initialPos.x, initialPos.y, initialPos.x + hourHandDirection.x * lengthMinutHand, initialPos.y + hourHandDirection.y * lengthMinutHand);

	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	SDL_RenderDrawLine(renderer, initialPos.x, initialPos.y, projectedPoint.x, projectedPoint.y);

	orthogonal = (projectedPoint - pointToBeProjected);
	float distanceYBeProjectProjected = orthogonal.magnitude();
	orthogonal.normalize();
	
	SDL_SetRenderDrawColor(renderer, 255, 255, 14, 255);
	for (int i = 0; i <= abs(distanceYBeProjectProjected); i +=4) {
		SDL_RenderDrawPoint(renderer, pointToBeProjected.x+orthogonal.x*i, pointToBeProjected.y+ orthogonal.y*i);
	}
}