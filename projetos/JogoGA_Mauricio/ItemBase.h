#pragma once

class ItemBase
{
public:
	ItemBase();
	~ItemBase();

	virtual void setPowerUp(int p_type) = 0;
	virtual int getPowerUp() = 0;
	virtual void setSpeed(float p_speed) = 0;
	virtual float getSpeed() = 0;

	virtual void powerUpActive();

	int powerUpType;
	float speed;
};

