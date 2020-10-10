#include "GameScreenManager.h"
#include "GameScreen.h"
#include "GameScreenLv1.h"
#include "GameScreenMenu.h"

GameScreenManager::GameScreenManager(SDL_Renderer* renderer, SCREENS startScreen)
{
	m_Renderer = renderer;
	m_CurrentScreen = NULL;
	ChangeScreens(startScreen);
}

GameScreenManager::~GameScreenManager()
{
	delete m_Renderer;
	m_Renderer = NULL;
	delete m_CurrentScreen;
	m_CurrentScreen = NULL;
}

void GameScreenManager::Update(float deltaTime, SDL_Event Event)
{
	m_CurrentScreen->Update(deltaTime, Event);
}
void GameScreenManager::Render()
{
	m_CurrentScreen->Render();
}

void GameScreenManager::ChangeScreens(SCREENS newScreens)
{
	if (m_CurrentScreen != NULL)
	{
		delete m_CurrentScreen;
	}
	GameScreenMenu* MenuScreen;
	GameScreenLv1* tempScreen;
	switch (newScreens)
	{
		case SCREEN_MENU:
		{
			tempScreen = new GameScreenLv1(m_Renderer);
			m_CurrentScreen = (GameScreen*)tempScreen;
			tempScreen = NULL;
			break;
			/*
			MenuScreen = new GameScreenMenu(m_Renderer);
			m_CurrentScreen = (GameScreen*)MenuScreen;
			MenuScreen = NULL;
			break;
			*/
		}

		case SCREEN_LEVEL1:
		{
			tempScreen = new GameScreenLv1(m_Renderer);
			m_CurrentScreen = (GameScreen*)tempScreen;
			tempScreen = NULL;
			break;
		}

		break;
	}
}