#pragma once
#include "libUnicornio.h"

class Tiro
{
public:
	Tiro();
	~Tiro();

	void setPosition(int p_x, int p_y);
	void setSpeed(float p_speed);
	void setSpriteSheet(string p_spriteSheet);

protected:
	Sprite sprite;
	float x, y;
	float speed;
};

