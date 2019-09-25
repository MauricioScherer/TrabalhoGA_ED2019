#include "Tiro.h"



Tiro::Tiro()
{
}


Tiro::~Tiro()
{
}

void Tiro::setPosition(int p_x, int p_y)
{
	x = p_x;
	y = p_y;
}

void Tiro::setSpeed(float p_speed)
{
	speed = p_speed;
}

void Tiro::setSpriteSheet(string p_spriteSheet)
{
	sprite.setSpriteSheet(p_spriteSheet);
}
