#include "GameScreenMenu.h"
#include "Texture2D.h"


GameScreenMenu::GameScreenMenu(SDL_Renderer* renderer) : GameScreen(renderer)
{
	SetUpMenu(renderer);
	ScreenToRender = 0;
}

GameScreenMenu::~GameScreenMenu()
{
	delete m_LevelBackgroundTexture;
	delete m_LevelBackgroundTexture2;
}

/*
void GameScreenMenu::Update(float deltaTime, SDL_Event ScreenEvent)
{
	
	if (ScreenToRender == 0)
	{
		ScreenToRender = 1;
	}
	else if (ScreenToRender == 1)
	{
		ScreenToRender = 0;
	}
	Render(m_ScreenRender);

}
void GameScreenMenu::Render(SDL_Renderer* renderer)
{
	if (ScreenToRender == 0)
	{
		m_LevelBackgroundTexture->Render(Vector2f(0, 0), SDL_FLIP_NONE);
	}
	else if (ScreenToRender == 1)
	{
		m_LevelBackgroundTexture2->Render(Vector2f(0, 0), SDL_FLIP_NONE);
	}
}
*/
bool GameScreenMenu::SetUpMenu(SDL_Renderer* Renderer)
{
	m_LevelBackgroundTexture = new Texture2D(Renderer);
	if (!m_LevelBackgroundTexture->LoadFromFile("Images/BackgroundTexture.bmp"));
	{
		std::cout << "Failed to load Texture!" << std::endl;
		return false;
	}
	m_LevelBackgroundTexture2 = new Texture2D(Renderer);
	if (!m_LevelBackgroundTexture->LoadFromFile("Images/BackgroundTexture2.bmp"));
	{
		std::cout << "Failed to load Texture!" << std::endl;
		return false;
	}
	m_Textures.push_back(m_LevelBackgroundTexture);
	m_Textures.push_back(m_LevelBackgroundTexture2);
	return true;


	/* THIS IS FUNCTIONAL, THE ABOVE IS NOT
	m_LevelBackgroundTexture = new Texture2D(Renderer);
	if (!m_LevelBackgroundTexture->LoadFromFile("Images/Mario.bmp"))
	{
		std::cout << "Failed to load Texture!" << std::endl;
		return false;
	}
	m_LevelBackgroundTexture2 = new Texture2D(Renderer);
	if (!m_LevelBackgroundTexture->LoadFromFile("Images/Luigi.bmp"))
	{
		std::cout << "Failed to load Texture!" << std::endl;
		return false;
	}
	
	return true;
	*/
}