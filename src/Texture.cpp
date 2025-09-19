#include "Texture.h"

Texture::Texture() {
	texture = NULL;
	width = 0;
	height = 0;
	x = 0;
	y = 0;
}

Texture::~Texture() {
	free();
}

void Texture::setColour(Uint8 r, Uint8 g, Uint8 b) {
	SDL_SetTextureColorMod(texture, r, g, b);
}

void Texture::setAlpha(Uint8 a) {
	SDL_SetTextureAlphaMod(texture, a);
}

// texture will not render, objects will have their own render
//void Texture::render() {
//	SDL_Rect renderQuad = { mX,mY, mWidth, mHeight };
//	SDL_RenderCopy(renderer, mTexture, NULL, &renderQuad);
//}

// might as well be public right?
int Texture::getWidth() { return width; }
int Texture::getHeight() { return height; }
int Texture::getX() { return x; }
int Texture::getY() { return y; }

void Texture::setX(int x) { x = x; }
void Texture::setY(int y) { y = y; }
void Texture::setWidth(int w) { width = w; }
void Texture::setHeight(int h) { height = h; }

// refactor these to the sprite class 
bool Texture::loadFromFile(std::string path) {
	free();
	SDL_Texture* newTexture = NULL;

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL) {
		std::cout << "Unable to load image: " << IMG_GetError() << std::endl;
	}
	else {
		newTexture = NULL;

		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));
		newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (newTexture == NULL) { std::cout << "Unable to create texture: " << SDL_GetError() << std::endl; }
		else {
			width = loadedSurface->w;
			height = loadedSurface->h;
		}

		SDL_FreeSurface(loadedSurface);
	}
	texture = newTexture;
	return texture != NULL;
}

void Texture::free() {
	if (texture != NULL) {
		SDL_DestroyTexture(texture);
		texture = NULL;
		width = 0;
		height = 0;
	}
}
