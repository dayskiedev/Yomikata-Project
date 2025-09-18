#pragma once

#include <iostream>

class Player
{
public:
	void Update();
	void Render();
private:
	int x;
	int y;

	int speed;
};