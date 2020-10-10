#pragma once
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_image.h>
#include <iostream>
#include "Texture2D.h"
#include "GameScreenManager.h"
#ifndef _ENGINE_H
#define _ENGINE_H
#endif // _ENGINE_H

class Engine
{
public:
	Engine();
	~Engine();
	void WorkingExample();
	bool InitSDL();
	void EngineMain();
	bool Update();
	void Render();
	void LoadMusic(string path);
	void DestroyWindow();
	void DestoryRenderer();
	void ClearRenderer();
	GameScreenManager* gameScreenManager;
	Uint32 g_Oldtime;
	Mix_Music* gMusic = NULL;
protected:
	bool Quit = false;
	bool Paused = false;
	SDL_Event m_PollEvent;
	SDL_Event m_KeyboardInput;
	SDL_Renderer* m_Renderer;
	SDL_Window* m_Window;
	SDL_Rect RenderLoaction = { 0, 0, 1920, 1080 };
	SDL_Texture* m_Texture;
};

