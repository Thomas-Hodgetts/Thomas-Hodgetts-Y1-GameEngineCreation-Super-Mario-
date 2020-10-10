#pragma once
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_image.h>
#include "SDL.h"
#include <iostream>
#include <vector>

using namespace std;


class Texture2D;

class Menu
{
public:
	Menu();
	~Menu();
	bool InitSDL();
	bool InitMenu();
	void Update();

private:

	SDL_Surface* ExampleSurface = NULL;
	SDL_Texture* ExampleTexture = NULL;
	SDL_Rect RenderLoaction = { 0, 0, 740, 512 };
	SDL_Window* Win = NULL;
	SDL_Renderer* Ren = NULL;
};
