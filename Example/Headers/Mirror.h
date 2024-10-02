#pragma once
#include <SDL.h>
#include "Drawable.h"
#include "Vector2.h"

class Mirror : public Drawable {
public:
	Mirror(int _x, int _y, Vector2 _direction, int _length);
	void draw(SDL_Renderer* renderer) override;
	void update()  override;

private: 
	int x, y;
	Vector2 mirrorDirection;
	int mirrorLength;
	Vector2 midlePointMirror;

	Vector2 emissionPoint;
	Vector2 emissionDirection;

	Vector2 reflectedPoint;
	Vector2 reflectedDirection;
	float reflectedLength;
	Vector2 mirrorNormal;
};

