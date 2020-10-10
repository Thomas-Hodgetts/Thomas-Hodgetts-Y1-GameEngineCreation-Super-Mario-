#include "POW_Block.h"
#include "Texture2D.h"
#include "LevelMap.h"

POW_Block::POW_Block(SDL_Renderer* renderer, LevelMap* map)
{
	m_Renderer = renderer;
	string imagePath = "Images/PowBlock.bmp";
	m_Texture = new Texture2D(renderer);
	if (!m_Texture->LoadFromFile(imagePath.c_str()))
	{
		cout << "failed to loat Texture" << imagePath << endl;
		return;
	}
	m_Map = map;
	m_singleSpriteHeight = m_Texture->GetHeigth();
	m_singleSpriteWidth = m_Texture->GetWidth();
	m_NumberOfHitsLeft = 3;
	m_Position = Vector2f((SCREEN_WIDTH * 0.5f) - m_singleSpriteWidth * 0.5f, 260);
}

POW_Block::~POW_Block()
{
	m_Renderer = NULL;
	delete m_Texture;
	m_Texture = NULL;
	m_Map = NULL;
}

Rectf POW_Block::GetCollisionBox()
{
	return Rectf(m_Position.X, m_Position.Y, m_Texture->GetWidth(), m_Texture->GetHeigth());
}

void POW_Block::TakeAHit()
{
	m_NumberOfHitsLeft--;
	if (m_NumberOfHitsLeft == 0)
	{
		m_Map->ChangeTileAt(8, 7, 0);
		m_Map->ChangeTileAt(8, 8, 0);
	}
}


void POW_Block::Render()
{
	if (m_NumberOfHitsLeft = 0)
	{
		return;
	}
	int left = m_singleSpriteWidth * (m_NumberOfHitsLeft - 1);
	SDL_Rect portionOfSpritesheet = { left, 0, m_singleSpriteWidth, m_singleSpriteHeight };
	SDL_Rect destRect = { (int)(m_Position.X), (int)(m_Position.Y), m_singleSpriteWidth, m_singleSpriteHeight };
	m_Texture->RenderRect(portionOfSpritesheet, destRect, SDL_FLIP_NONE, 0.f);
}
