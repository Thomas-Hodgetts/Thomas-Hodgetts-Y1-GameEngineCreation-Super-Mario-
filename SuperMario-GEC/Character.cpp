#include "Character.h"
#include "Texture2D.h"
#include "LevelMap.h"

Character::Character(SDL_Renderer* Renderer, string imagePath, Vector2f startPosition, LevelMap* map)
{
	m_Renderer = Renderer;
	m_Texture = new Texture2D(m_Renderer);
	m_Texture->LoadFromFile(imagePath);
	m_Position = startPosition;
	m_FacingDirection = FACING_RIGHT;
	m_MovingLeft = false;
	m_MovingRight = false;
	m_Jumping = false;
	m_CanJump = false;
	m_CollistionRadius = 15.f;
	m_CurrentLevelMap = map;
}

Character::~Character()
{
	m_Renderer = NULL;
	delete m_Texture;
}

void Character::Render()
{
	int left = 0.f;
	if (m_FacingDirection == FACING_RIGHT)
	{
		SDL_Rect proportionOfSpriteSheet = { left, 0, m_Texture->GetWidth() , m_Texture->GetHeigth() };
		SDL_Rect destRect = { (int)(m_Position.X), (int)(m_Position.Y),  m_Texture->GetWidth() , m_Texture->GetHeigth() };
		m_Texture->RenderRect(proportionOfSpriteSheet, destRect, SDL_FLIP_NONE);
	}
	else
	{
		SDL_Rect proportionOfSpriteSheet = { left, 0, m_Texture->GetWidth() , m_Texture->GetHeigth() };
		SDL_Rect destRect = { (int)(m_Position.X), (int)(m_Position.Y),  m_Texture->GetWidth() , m_Texture->GetHeigth() };
		m_Texture->RenderRect(proportionOfSpriteSheet, destRect, SDL_FLIP_HORIZONTAL);
	}
}

void Character::Update(float deltaTime, SDL_Event Event)
{
	int centralXPosition = (int)(m_Position.X + (m_Texture->GetWidth() * 0.5)) / TILE_HEIGHT;
	int footPosition = (int)(m_Position.Y + (m_Texture->GetHeigth() * 0.5)) / TILE_WIDTH;
	
	if (m_CurrentLevelMap->GetTileAt(footPosition, centralXPosition) == 0)
	{
		AddGravity(deltaTime);
	}
	else
	{
		m_CanJump = true;
	}
	if (m_Jumping)
	{
		//adjusts the position
		m_Position.Y -= m_JumpForce * deltaTime;
		//reduces jump force
		m_JumpForce -= JUMP_FORCE_DECREMENT * deltaTime;
		//Checks if the jump is in progress
		if (m_JumpForce <= 0.f)
		{
			m_Jumping = false;
		}

	}
	if (m_MovingLeft)
	{
		MoveLeft(deltaTime);
	}
	else if (m_MovingRight)
	{
		MoveRight(deltaTime);
	}
	switch (Event.key.keysym.sym)
	{
	case SDL_KEYDOWN:
	{
		switch (Event.key.keysym.sym)
		{
			case SDLK_i:
			{
				m_MovingRight = true;
				m_MovingLeft = false;
			}
			case SDLK_o:
			{
				m_MovingRight = false;
				m_MovingLeft = true;
			}
			case SDLK_RIGHT:
			{

				m_MovingRight = true;
				m_MovingLeft = false;

			}
			case SDLK_LEFT:
			{
				m_MovingRight = false;
				m_MovingLeft = true;
			}
			case SDLK_SPACE:
			{
				Jump();
			}
		}
	}

	case SDL_KEYUP:

 		switch (Event.key.keysym.sym)
		{
			case SDLK_RIGHT:
			{
				m_MovingRight = false;

			}
			case SDLK_LEFT:
			{
				m_MovingLeft = false;
			}
			case SDLK_SPACE:
			{
				break;
			}
		}
	break;
	}
}

void Character::SetPosition(Vector2f newPosition)
{
	m_Position = newPosition;
}

Vector2f Character::GetPosition()
{
	return m_Position;
}

void Character::MoveLeft(float deltaTime)
{
	m_FacingDirection = FACING_LEFT;
	m_Position.X = -1.f;
}
void Character::MoveRight(float deltaTime)
{
	m_Position.X = +1.f;
	m_FacingDirection = FACING_RIGHT;
}

void Character::AddGravity(float deltaTime)
{
	if (m_Position.Y > -1080)
	{
		m_Position.Y += gravityStrength * deltaTime;
		m_CanJump = false;
	}
}

void Character::Jump()
{
	if (!m_Jumping)
	{
		m_JumpForce = INITIAL_JUMP_FORCE;
		m_Jumping = true;
		m_CanJump = false;
	}
}

float Character::GetCollisionRadius()
{
	return m_CollistionRadius;
}

Rectf Character::GetCollisionBox()
{
	return Rectf(m_Position.X, m_Position.Y, m_Texture->GetWidth(), m_Texture->GetHeigth());
}

void Character::CancelJump()
{
	return;
}

bool Character::IsJumping()
{
	return false;
}