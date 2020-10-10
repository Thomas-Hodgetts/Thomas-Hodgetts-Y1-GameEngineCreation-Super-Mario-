#pragma once
#include "GameScreen.h"
#include <vector>

class Texture2D;

class GameScreenMenu : public GameScreen
{
public:
	GameScreenMenu(SDL_Renderer* renderer);
	~GameScreenMenu();


	//void Render(SDL_Renderer* renderer);
	//void Update(float deltaTime, SDL_Event ScreenEvent);
private:

	int ScreenToRender;
	bool SetUpMenu(SDL_Renderer* Renderer);
	Texture2D* m_LevelBackgroundTexture;
	Texture2D* m_LevelBackgroundTexture2;
	vector<Texture2D*> m_Textures;
};

