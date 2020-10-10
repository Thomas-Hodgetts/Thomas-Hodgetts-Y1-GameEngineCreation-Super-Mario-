#include "Engine.h"


Engine::Engine()
{
	if (InitSDL())
	{
		gameScreenManager = new GameScreenManager(m_Renderer, SCREEN_LEVEL1); //SCREEN_MENU
		g_Oldtime = SDL_GetTicks();
		LoadMusic("Music/Mario.mp3");
		if (Mix_PlayingMusic() == 0)
		{
			Mix_PlayMusic(gMusic, -1);
		}
		EngineMain();

	}
}

Engine::~Engine()
{
	DestroyWindow();
	Mix_FreeMusic(gMusic);
	gMusic = NULL;
	delete gameScreenManager;
	SDL_Quit();
}

void Engine::EngineMain()
{
	while (!Quit)
	{
		Render();
		Quit = Update();

	}
}

bool Engine::Update()
{
	Uint32 newTime = SDL_GetTicks();
	SDL_PollEvent(&m_PollEvent);

	switch (m_PollEvent.type)
	{
		case SDL_QUIT:
		{
			return true;
		}
		case  SDL_KEYUP:
			switch(m_PollEvent.key.keysym.sym)
			{
				case SDLK_p:
					{
					std::cout << "p" << std::endl;
					//gameScreenManager->ChangeScreens(SCREEN_LEVEL1);

					}
					break;
			}
			
	break;
	}
	gameScreenManager->Update((float)(newTime - g_Oldtime) / 1000.0f, m_PollEvent);
	g_Oldtime = newTime;
	return false;
}

void Engine::Render()
{
	//sets Draw colour
	SDL_SetRenderDrawColor(m_Renderer, 0xff, 0xff, 0xff, 0xff);

	//Renders to screen;
	gameScreenManager->Render();
	//Updates the screen
	SDL_RenderPresent(m_Renderer);
}


bool Engine::InitSDL()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) //This makes sure the flags for SDL are equal to 0, if -1 and error has occured and aspects have not initialised.
	{
		std::cout << "SDL did not initialise. Error: " << SDL_GetError();
		return false;
	}
	else //if the flags indicate successful init, these commands shall run	
	{
		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
		{
			cout << "Mixer could not init. Error: " << Mix_GetError();
			return false;
		}
		//this creates and sets information for the window
		//SDL_CreateWindowAndRenderer(500, 500, SDL_WINDOW_RESIZABLE, &gWindow, &gRenderer);
		m_Window = SDL_CreateWindow("Games Engine Creation", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1080, SDL_WINDOW_SHOWN);
		m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);
		if (m_Renderer == NULL)
		{
			std::cout << "Render was not created. Error: " << SDL_GetError();
			return false;
		}
		if (m_Window == NULL)
		{
			std::cout << "Window was not created. Error: " << SDL_GetError();
			return false;
		}
		
	}
	return true;
}


void Engine::WorkingExample()
{
	SDL_Surface* ExampleSurface = NULL;
	SDL_Texture* ExampleTexture = NULL;
	SDL_Rect RenderLoaction = { 0, 0, 740, 512};
	SDL_Window* Win = NULL;
	SDL_Renderer* Ren = NULL;
	if (SDL_Init(SDL_INIT_VIDEO) < 0) //This makes sure the flags for SDL are equal to 0, if -1 and error has occured and aspects have not initialised.
	{
		std::cout << "SDL did not initialise. Error: " << SDL_GetError();

	}
	else //if the flags indicate successful init, these commands shall run	
	{
		//this creates and sets information for the window
		SDL_CreateWindowAndRenderer(500, 500, SDL_WINDOW_RESIZABLE, &Win, &Ren);
		//gWindow = SDL_CreateWindow("Games Engine Creation", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _pubVariables_R.resolutionX, _pubVariables_R.resolutionY, SDL_WINDOW_SHOWN);
		//gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
		if (Ren == NULL)
		{
			std::cout << "Render was not created. Error: " << SDL_GetError();

		}
		if (Win == NULL)
		{
			std::cout << "Window was not created. Error: " << SDL_GetError();
		}

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
		//Renders to screen;
		SDL_RenderCopyEx(Ren, ExampleTexture, NULL, &RenderLoaction, 0, NULL, SDL_FLIP_NONE);
		//Updates the screen
		SDL_RenderPresent(Ren);

		SDL_Delay(1000);
	}
}


void Engine::ClearRenderer()
{
	SDL_SetRenderDrawColor(m_Renderer, 0xff, 0xff, 0xff, 0xff);
	SDL_RenderClear(m_Renderer);
}

void Engine::DestroyWindow()
{
	SDL_DestroyWindow(m_Window);
	DestoryRenderer();
	return;
}

void Engine::DestoryRenderer()
{
	m_Renderer = NULL;
}

void Engine::LoadMusic(string path)
{

	gMusic = Mix_LoadMUS(path.c_str());
	if (gMusic == NULL)
	{
		cout << "Failed to load Background music! ERROR: " << Mix_GetError() << endl;
	}

}