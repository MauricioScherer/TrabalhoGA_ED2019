#include "Player.h"

Player::Player()
{

}


Player::~Player()
{
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
