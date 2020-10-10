#include "MarioCharacter.h"
#include "Texture2D.h"

MarioCharacter::MarioCharacter(SDL_Renderer* Renderer, string imagePath, Vector2f startPosition, LevelMap* map) : Character(Renderer, imagePath, startPosition, map)
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
	m_JumpForce = 0;
}

MarioCharacter::~MarioCharacter()
{
	m_Renderer = NULL;
	delete m_Texture;
}

void Character::SetState(CHARACTER_STATE state)
{
	m_State = state;
}

void Character::Update(float deltaTime, SDL_Event Event)
{
	AddGravity(deltaTime);
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