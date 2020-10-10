#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Commons.h"

#ifndef _TEXTURE2D_H
#define _TEXTURE2D_H
#endif // _TEXTURE2D_H



class Texture2D
{
public:
	Texture2D(SDL_Renderer* renderer);
	~Texture2D();

	bool LoadFromFile(string path);
	void Free();
	void Render(Vector2f newPosition, SDL_RendererFlip flip, double angle = 0.0f);
	void RenderRect(SDL_Rect src, SDL_Rect destRect, SDL_RendererFlip flip, double angle = 0.0f);
	int GetWidth()  {return m_Width;};
	int GetHeigth() {return m_Height;};

private:
	SDL_Renderer* m_TexRenderer;
	SDL_Texture* m_TexTexture;
	SDL_Rect RenderLoaction = { 0, 0, 1920, 1080 };

	int m_Width;
	int m_Height;
};

