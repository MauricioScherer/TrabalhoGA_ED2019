#pragma once
#include "libUnicornio.h"
#include "Tiro.h"

class Player : public Tiro
{
public:
	Player();
	~Player();
	
	void playerInicializar();
	void setPosition(int p_x, int p_y);
	void setSpeed(float p_speed);
	float getSpeed();
	void setSpriteSheet(string p_spriteSheet);

	void move();
	void shoot();
	void draw();

	Sprite getSprite();
	int getPosX();
	int getPosY();
	float getRot();
	void setIsShoot(bool p_status);
	bool getIsShoot();

protected:
	Sprite sprite;
	float x, y;
	float speed;
	bool isShoot;
};