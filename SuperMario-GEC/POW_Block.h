#pragma once
#include "SDL.h"

#include "Commons.h"

class LevelMap;
class Texture2D;

class POW_Block
{
public: 

	POW_Block(SDL_Renderer* renderer, LevelMap* map);
	~POW_Block();
	void Render();
	Rectf GetCollisionBox();
	void TakeAHit();
	bool IsAvailable() { return m_NumberOfHitsLeft > 0; };

private:

	SDL_Renderer* m_Renderer;
	Vector2f m_Position;
	Texture2D* m_Texture;
	LevelMap* m_Map;

	float m_singleSpriteWidth;
	float m_singleSpriteHeight;
	int m_NumberOfHitsLeft;

};

