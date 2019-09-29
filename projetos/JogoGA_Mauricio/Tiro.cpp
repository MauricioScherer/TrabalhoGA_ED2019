#include "Tiro.h"



Tiro::Tiro()
{
}


Tiro::~Tiro()
{
}

void Tiro::tiroSetPosition(int p_x, int p_y)
{
	x = p_x;
	y = p_y;
}

void Tiro::tiroSetSpeed(float p_speed)
{
	speed = p_speed;
}

float Tiro::tiroGetSpeed()
{
	return speed;
}

void Tiro::tiroSetSpriteSheet(string p_spriteSheet)
{
	sprite.setSpriteSheet(p_spriteSheet);
}

void Tiro::tiroMoveShot()
{
	y -= speed;
}

void Tiro::tiroDraw()
{
	sprite.desenhar(x, y);
}

Sprite Tiro::tiroGetSprite()
{
	return sprite;
}

int Tiro::tiroGetPosX()
{
	return x;
}

int Tiro::tiroGetPosY()
{
	return y;
}
