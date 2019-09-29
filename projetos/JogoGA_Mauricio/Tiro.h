#pragma once
#include "libUnicornio.h"

class Tiro
{
public:
	Tiro();
	~Tiro();

	void tiroSetPosition(int p_x, int p_y);
	void tiroSetSpeed(float p_speed);
	float tiroGetSpeed();
	void tiroSetSpriteSheet(string p_spriteSheet);

	void tiroMoveShot();
	void tiroDraw();
	Sprite tiroGetSprite();
	int tiroGetPosX();
	int tiroGetPosY();

private:
	Sprite sprite;
	float x, y;
	float speed;
};

