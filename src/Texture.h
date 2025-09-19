#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#ifndef TEXTURE_H
#define TEXTURE_H

// updated texture from sdlvn
// we want to seperate the texture directly from rendering

class Texture {
public:
	Texture();
	~Texture();

	void setColour(Uint8 r, Uint8 g, Uint8 b);

	void setAlpha(Uint8 a);

	// might as well be public right?
	int getWidth();
	int getHeight();
	int getX();
	int getY();

	void setX(int x);
	void setY(int y);
	void setWidth(int w);
	void setHeight(int h);

	// refactor these to the sprite class 
	bool loadFromFile(std::string path);

	void free();

private:
	SDL_Texture* texture = NULL;

	int width;
	int height;
	int x;
	int y;
};

#endif