#include "Clock.h" 
#include "Settings.h"
#include <SDL_ttf.h>

Clock::Clock(int x, int y, SDL_Renderer* renderer) {
	initialPos.x = x;
	initialPos.y = y;
	theta = 0.01;
	minutHandDirection = Vector2::right;
	lengthMinutHand = 50;
	hourHandDirection = Vector2::right;
	lengthHourHand = 50;
}
 
void Clock::update() {
	hourHandDirection.RotatedRadians(theta);
} 

void Clock::draw(SDL_Renderer* renderer)   {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);  
	SDL_RenderDrawLine(renderer, initialPos.x, initialPos.y, initialPos.x + minutHandDirection.x * lengthMinutHand, initialPos.y + minutHandDirection.y * lengthMinutHand);
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

	arc = minutHandDirection.normalized();
	arcAngle  = 0;

	while (arcAngle <= Vector2::AngleInRadians(arc,hourHandDirection)) {
		arcAngle+=0.0005;
		arc.RotatedRadians(theta);
		SDL_RenderDrawPoint(renderer, initialPos.x + arc.x * 10, initialPos.y + arc.y * 10);
	}

	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	SDL_RenderDrawLine(renderer, initialPos.x, initialPos.y, initialPos.x + hourHandDirection.x * lengthHourHand, initialPos.y + hourHandDirection.y * lengthHourHand);	 
}