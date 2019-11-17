#pragma once
#include <string>

using namespace std;

class Usuario
{
public:
	Usuario();
	~Usuario();
	void setName(string p_name);
	string getName();
	void setPassword(string p_password);
	string getPassword();
	void setPoints(int p_points);
	int getPoints();

private:
	string name;
	string password;
	int points;
};

