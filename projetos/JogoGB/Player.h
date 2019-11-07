#pragma once
#include <string>

using namespace std;

class Player
{
public:
	Player();
	~Player();

	string GetName();
	string GetPassword();
	int GetPoint();

	void SetName(string p_name);
	void SetPassword(string p_password);
	void SetPoint(int p_point);

private:
	string name, password;
	int point;
};

