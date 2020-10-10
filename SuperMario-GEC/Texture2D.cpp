#include "Texture2D.h"

Texture2D::Texture2D(SDL_Renderer* renderer)
{
	m_Width = 0;
	m_Height = 0;
	m_TexTexture = nullptr;
	m_TexRenderer = renderer;
}

Texture2D::~Texture2D()
{
	Free();
	m_TexTexture = nullptr;
	m_TexRenderer = nullptr;
}


void Texture2D::Free()
{
	if (!m_TexTexture == NULL)
	{
		SDL_DestroyTexture(m_TexTexture);
		m_Width = 0;
		m_Height = 0;
		return;
	}
	return;
}

bool Texture2D::LoadFromFile(string path)
{

	Free();
	SDL_Surface* bitmapSurface = SDL_LoadBMP(path.c_str());
	if (bitmapSurface == NULL)
	{
		cout << IMG_GetError() << endl;
	}
	SDL_SetColorKey(bitmapSurface, SDL_TRUE, SDL_MapRGB(bitmapSurface->format, 0, 0xFF, 0xFF));
	m_Height = bitmapSurface->h;
	m_Width = bitmapSurface->w;
	if (bitmapSurface != NULL)
	{
		m_TexTexture = SDL_CreateTextureFromSurface(m_TexRenderer, bitmapSurface);
		if (m_TexTexture == NULL)
		{
			std::cout << "Unable to create texture from surface. Error: " << SDL_GetError() << std::endl;
			return false;
		}
		SDL_FreeSurface(bitmapSurface);
	}
	else
	{
		std::cout << "Unahble to create Texture from surface. Error: " << IMG_GetError() << std::endl;
		return false;

	}
	return m_TexTexture != NULL;

}



void Texture2D::Render(Vector2f newPosition, SDL_RendererFlip flip, double angle)
{
	RenderLoaction.x = newPosition.X;
	RenderLoaction.y = newPosition.Y;
	//Renders to screen;
	SDL_RenderCopyEx(m_TexRenderer, m_TexTexture, NULL, &RenderLoaction, 0, NULL, flip);
}

void Texture2D::RenderRect(SDL_Rect src, SDL_Rect destRect, SDL_RendererFlip flip, double angle)
{
	SDL_RenderCopyEx(m_TexRenderer, m_TexTexture, &src, &destRect, angle, NULL, flip);
}