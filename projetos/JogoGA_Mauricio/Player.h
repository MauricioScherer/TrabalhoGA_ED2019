#pragma once
#include "libUnicornio.h"
#include "Tiro.h"

class Player : public Tiro
{
public:
	Player();
	~Player();

	void setPosition(int p_x, int p_y);
	void setSpeed(float p_speed);
	void setSpriteSheet(string p_spriteSheet);

	void move();
	void draw();

	Sprite getSprite();
	int getPosX();
	int getPosY();
	float getRot();

protected:
	Sprite sprite;
	float x, y;
	float speed;
};