#include "Koopa.h"
#include "Texture2D.h"

Koopa::Koopa(SDL_Renderer* Renderer, string imagePath, Vector2f startPosition, LevelMap* map, FACING startFacing, float movementSpeed) : Character(Renderer, imagePath, startPosition, map)
{
	m_FacingDirection = startFacing;
	m_MovementSpeed = movementSpeed;
	m_Position = startPosition;
	m_Injured = false;
	m_SingleSpriteWidth = m_Texture->GetWidth() / 2;
	m_SingleSpriteHeight = m_Texture->GetHeigth();
}
Koopa::~Koopa()
{

}

void Koopa::Render()
{
	int left = 0.f;
	if (m_Injured)
	{
		left = m_SingleSpriteWidth;
	}
	SDL_Rect proportionOfSpriteSheet = { left, 0, m_SingleSpriteWidth, m_SingleSpriteHeight };
	SDL_Rect destRect = { (int)(m_Position.X), (int)(m_Position.Y), m_SingleSpriteWidth, m_SingleSpriteHeight };
	switch (m_FacingDirection)
	{
	case 0:
		m_Texture->RenderRect(proportionOfSpriteSheet, destRect, SDL_FLIP_NONE);
	case 1:
		m_Texture->RenderRect(proportionOfSpriteSheet, destRect, SDL_FLIP_HORIZONTAL);
	
	break;
	}
}

void Koopa::Update(float deltaTime, SDL_Event e)
{
	Character::Update(deltaTime, e);
	if (!m_Injured)
	{
		if (m_Position.X < 0)
		{
			m_FacingDirection = FACING_RIGHT;
		}
		else if (m_Position.X > 1920)
		{
			m_FacingDirection = FACING_LEFT;
		}
		switch (m_FacingDirection)
		{
		case 00:
			m_MovingLeft = true;
			m_MovingRight = false;
		case 01:
			m_MovingLeft = false;
			m_MovingRight = true;

			break;
		}
	}
	else
	{
		m_MovingLeft = false;
		m_MovingRight = false;

		m_InjuredTime -= deltaTime;
		if (m_InjuredTime <= 0.0)
		{
			FlipRightWayUp();
		}
	}
}

void Koopa::TakeDamage()
{
	m_Injured = true;
	m_InjuredTime = INJURE_TIME;
	Jump();
}

void Koopa::Jump()
{
	if (!m_Jumping)
	{
		m_JumpForce = INITIAL_JUMP_FORCE;
		m_Jumping = true;
		m_CanJump = false;
	}
}


void Koopa::FlipRightWayUp()
{
	switch (m_FacingDirection)
	{
	FACING_LEFT:
		m_FacingDirection = FACING_RIGHT;
		m_Injured = false;
		Jump();
	FACING_RIGHT:
		m_FacingDirection = FACING_LEFT;
		m_Injured = false;
		Jump();
	break;
	}
}

Vector2f Koopa::GetPosition()
{
	return m_Position;
}

/*
Rectf Character::GetCollisionBox()
{
	return Rectf(m_Position.X, m_Position.Y, m_Texture->GetWidth(), m_Texture->GetHeigth());
}
*/
bool Koopa::GetAlive()
{
	switch (m_EnemyState)
	{
	case ENEMY_ALIVE:
		return true;
	case ENEMY_DEATH:
		return false;
	}
	
}

void Koopa::SetAlive(bool state)
{
	switch (state)
	{
	case true:
		m_EnemyState = ENEMY_ALIVE;
	case false:
		m_EnemyState = ENEMY_DEATH;
	}

}

bool Koopa::GetInjured()
{
	switch (m_Injured)
	{
	case true:
		return true;
	case false:
		return false;
	}
}