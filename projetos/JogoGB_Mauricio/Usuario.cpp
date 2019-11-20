#include "Usuario.h"

Usuario::Usuario()
{
}

Usuario::Usuario(string p_name, string p_password)
{
	name = p_name;
	password = p_password;
	points = 0;
}


Usuario::~Usuario()
{
}

void Usuario::setName(string p_name)
{
	name = p_name;
}

string Usuario::getName()
{
	return name;
}

void Usuario::setPassword(string p_password)
{
	password = p_password;
}

string Usuario::getPassword()
{
	return password;
}

void Usuario::setPoints(int p_points)
{
	points = p_points;
}

int Usuario::getPoints()
{
	return points;
}
