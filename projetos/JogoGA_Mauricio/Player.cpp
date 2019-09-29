#include "Player.h"

Player::Player()
{
}


Player::~Player()
{
}

void Player::playerInicializar()
{
	setPosition(gJanela.getLargura() / 2, gJanela.getAltura() - 30);
	setSpeed(1.0f);

	tiroSetPosition(0, 0);
	tiroSetSpeed(5.0f);
}

void Player::setPosition(int p_x, int p_y)
{
	x = p_x;
	y = p_y;
}

void Player::setSpeed(float p_speed)
{
	speed = p_speed;
}

float Player::getSpeed()
{
	return speed;
}

void Player::setSpriteSheet(string p_spriteSheet)
{
	sprite.setSpriteSheet(p_spriteSheet);
}

void Player::move()
{
	if (gTeclado.segurando[TECLA_DIR] && x < gJanela.getLargura() - 20)
		x += speed;
	else if (gTeclado.segurando[TECLA_ESQ] && x > 20)
		x -= speed;

	if (gTeclado.segurando[TECLA_CIMA] && y > 40)
		y -= speed;
	else if (gTeclado.segurando[TECLA_BAIXO] && y < gJanela.getAltura() - 40)
		y += speed;
}

void Player::shoot()
{		
	if (gTeclado.soltou[TECLA_ESPACO] && !isShoot)
	{
		tiroSetPosition(x, y - 20);
		isShoot = true;
	}

	if (isShoot)
	{
		tiroMoveShot();
		tiroDraw();

		if (tiroGetPosY() < -20)
		{
			tiroSetPosition(0, 0);
			isShoot = false;
		}
	}
}

void Player::draw()
{
	sprite.desenhar(x, y);
}

Sprite Player::getSprite()
{
	return sprite;
}

int Player::getPosX()
{
	return x;
}

int Player::getPosY()
{
	return y;
}

float Player::getRot()
{
	return 0.0f;
}

void Player::setIsShoot(bool p_status)
{
	isShoot = p_status;
}

bool Player::getIsShoot()
{
	return isShoot;
}
