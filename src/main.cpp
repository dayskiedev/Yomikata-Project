#include <SDL.h>

#include <stdio.h>
#include <iostream>

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

enum GAME_STATE
{
	MAIN_MENU,
	GAME
};

// define rectangle that has a position and size
// just follows players position everywhere, that way we check collision between boxes and not the player
// need some sort of spawener for projectiles from both the player and the enemy
// enemy uses math n shit for spawning, delays between each attack, another fileformat?
// enemy can spawn emitters that spawn bullets...

// all bullets have a start position
// and move a certain amount
// ie they dissapear when they:
// - hit the edge of the screen
// - hit the player
// - are caught in the blank (blowing them up)

// enemy can spawn them

// most basic enemy type:
// - move down the screen in a straight line

// most basic boss type:
// - stick to the top of the screen and fire bullets that go straight down

// the window we render to
SDL_Window* gWindow = NULL;

// the surface contaiine in the window
SDL_Surface* gScreenSurface = NULL;
SDL_Renderer* gRenderer = NULL;

// current displayed image
SDL_Surface* gCurrentSurface = NULL;


bool init() {
	bool success = true;

	//initialze sdl
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL could not be initialized!" << std::endl;
	}
	else {
		// Create window
		gWindow = SDL_CreateWindow("SDL_Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
		SDL_SetRenderDrawColor(gRenderer, 255, 175, 222, 0xFF);
		SDL_SetRenderDrawBlendMode(gRenderer, SDL_BLENDMODE_BLEND);
	}

	return success;
}

void close() {
	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	//Quit SDL
	SDL_Quit();
	// we dont technically need to do all this, but its better safe than siorry
}

// loads individual image
SDL_Surface* loadSurface(std::string path) {
	// Load image at a specified path
	SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
	if (loadedSurface == NULL) {
		std::cout << "Unable to lead image! " << SDL_GetError() << std::endl;
		loadedSurface = SDL_LoadBMP("gmap.bmp");
	}

	return loadedSurface;
}


void render() {
	SDL_SetRenderDrawColor(gRenderer, 255, 200, 255, 255);
	SDL_RenderClear(gRenderer);

	// vector of objects to render, some sort of z buffer?

	SDL_RenderPresent(gRenderer);
}
int main(int argc, char* args[]) {
	bool quit = false;
	SDL_Event e;

	if (!init()) {
		std::cout << "Failed to Init!" << std::endl;
		return -1;
	}

	std::cout << "running" << std::endl;

	//while application is running
	while (!quit) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				quit = true;
			}
		}
		render();
	}
	close();
	return 0;
}