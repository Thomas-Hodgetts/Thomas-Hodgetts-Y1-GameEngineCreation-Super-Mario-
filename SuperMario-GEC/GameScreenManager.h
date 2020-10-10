#pragma once
#include "SDL.h"
#include "Commons.h"

class GameScreen;

class GameScreenManager
{
public:
	GameScreenManager(SDL_Renderer* renderer, SCREENS startScreen);
	~GameScreenManager();

	void Render();
	void Update(float deltaTime, SDL_Event Event);
	void ChangeScreens(SCREENS newScreen);
private:
	SDL_Renderer* m_Renderer;
	GameScreen * m_CurrentScreen;
};
