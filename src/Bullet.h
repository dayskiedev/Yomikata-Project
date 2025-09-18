#include <iostream>
#pragma once

// Most basic version of a bullet, used by every entity that uses a bullet
struct Bullet {
	float x, y;
	float speed;
	// Texture bulletTexture

	// Bullet constructor for spawning bullet
	Bullet(float sX, float sY, float sSpeed);

	void Render();
	void Update();
};