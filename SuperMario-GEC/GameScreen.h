#pragma once
#include <SDL.h>
#include "Collision.h"

class GameScreen
{
public:
	GameScreen(SDL_Renderer* renderer);
	~GameScreen();

	virtual void Render();
	virtual void Update(float deltaTime, SDL_Event ScreenEvent);

protected:
	SDL_Renderer* m_ScreenRender;

};

