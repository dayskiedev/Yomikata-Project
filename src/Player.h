#include <iostream>

#include "Texture.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player : Texture {
public:
	Player();
	void Update();
	void Render();
private:
	int x;
	int y;

	int speed;

	Texture playerSprite;
};

#endif