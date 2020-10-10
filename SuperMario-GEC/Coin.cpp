#include "Coin.h"
#include "Texture2D.h"


Coin::Coin(SDL_Renderer* Renderer, string imagePath, Vector2f startPosition, LevelMap* map, FACING startFacing) : Character (Renderer, imagePath, startPosition, map)
{
	m_FacingDirection = startFacing;
	m_State = COIN_AVAILABLE;
	m_SingleSpriteWidth = m_Texture->GetWidth() / 3;
	m_SingleSpriteHeight = m_Texture->GetHeigth();
}


void Coin::Update(float deltaTime, SDL_Event e)
{
	Character::Update(deltaTime, e);
	if (m_State == 0)
	{
		switch (m_FacingDirection)
		{
		FACING_LEFT:
			m_MovingLeft = true;
			m_MovingRight = false;
		FACING_RIGHT:
			m_MovingLeft = false;
			m_MovingRight = true;

			break;
		}
		m_FrameDelay -= deltaTime;
		if (m_FrameDelay <= 0.0f)
		{
			m_FrameDelay = ANIMATION_DELAY;
			m_CurrentFrame++;
			if (m_CurrentFrame > 2)
			{
				m_CurrentFrame = 0;
			}
		}
	}
}

void Coin::Render()
{
	int left = m_CurrentFrame * m_SingleSpriteWidth;
	SDL_Rect proportionOfSpriteSheet = { left, 0, m_SingleSpriteWidth, m_SingleSpriteHeight };
	SDL_Rect destRect = { (int)(m_Position.X), (int)(m_Position.Y), m_SingleSpriteWidth, m_SingleSpriteHeight };
	switch (m_FacingDirection)
	{
	FACING_LEFT:
		m_Texture->RenderRect(proportionOfSpriteSheet, destRect, SDL_FLIP_NONE);
	FACING_RIGHT:
		m_Texture->RenderRect(proportionOfSpriteSheet, destRect, SDL_FLIP_HORIZONTAL);

		break;
	}
}

/*
Rectf Character::GetCollisionBox()
{
	return Rectf(m_Position.X, m_Position.Y, m_Texture->GetWidth(), m_Texture->GetHeigth());
}
*/