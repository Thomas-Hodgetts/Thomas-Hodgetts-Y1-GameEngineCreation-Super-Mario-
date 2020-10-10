#include "Menu.h"


Menu::Menu()
{
	ExampleSurface = NULL;
	ExampleTexture = NULL;
	RenderLoaction = { 0, 0, 740, 512 };
	Win = NULL;
	Ren = NULL;
}
Menu::~Menu()
{
}


bool Menu::InitSDL()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) //This makes sure the flags for SDL are equal to 0, if -1 and error has occured and aspects have not initialised.
	{
		std::cout << "SDL did not initialise. Error: " << SDL_GetError();
		return false;
	}
	else //if the flags indicate successful init, these commands shall run	
	{
		//this creates and sets information for the window
		//SDL_CreateWindowAndRenderer(500, 500, SDL_WINDOW_RESIZABLE, &gWindow, &gRenderer);
		Win = SDL_CreateWindow("Games Engine Creation", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1080, SDL_WINDOW_SHOWN);
		Ren = SDL_CreateRenderer(Win, -1, SDL_RENDERER_ACCELERATED);
		if (Ren == NULL)
		{
			std::cout << "Render was not created. Error: " << SDL_GetError();
			return false;
		}
		if (Win == NULL)
		{
			std::cout << "Window was not created. Error: " << SDL_GetError();
			return false;
		}
	}
	return true;
}

bool Menu::InitMenu()
{
	ExampleSurface = SDL_LoadBMP("Images/Tuna.bmp");
	if (ExampleSurface != NULL)
	{
		ExampleTexture = SDL_CreateTextureFromSurface(Ren, ExampleSurface);
		if (ExampleTexture == NULL)
		{
			std::cout << "Unable to create texture from surface. Error: " << SDL_GetError() << std::endl;
		}
		SDL_FreeSurface(ExampleSurface);
	}
	else
	{
		std::cout << "Unahble to create Texture from surface. Error: " << IMG_GetError() << std::endl;
	}
	return true;
}

void Menu::Update()
{
}
;