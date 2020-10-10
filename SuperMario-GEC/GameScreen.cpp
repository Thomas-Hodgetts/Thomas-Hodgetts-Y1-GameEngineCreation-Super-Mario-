#include "GameScreen.h"

GameScreen::GameScreen(SDL_Renderer* renderer)
{
	m_ScreenRender = renderer;
}

GameScreen::~GameScreen()
{
	m_ScreenRender = NULL;
}

void GameScreen::Render()
{

}
void GameScreen::Update(float deltaTime, SDL_Event ScreenEvent)
{

}