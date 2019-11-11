#include "Player.h"

Player::Player()
{
	name = "Admin";
	password = "1234";
	point = 0;
}

Player::~Player()
{
}

string Player::GetName()
{
	return name;
}

string Player::GetPassword()
{
	return password;
}

int Player::GetPoint()
{
	return point;
}

void Player::SetName(string p_name)
{
	name = p_name;
}

void Player::SetPassword(string p_password)
{
	password = p_password;
}

void Player::SetPoint(int p_point)
{
	point = p_point;
}
