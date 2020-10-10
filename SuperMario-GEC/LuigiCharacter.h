#pragma once
#include "Character.h"
class LuigiCharacter : public Character
{
public:
	LuigiCharacter(SDL_Renderer* Renderer, string imagePath, Vector2f startPosition, LevelMap* map);
	~LuigiCharacter();
private:
	FACING m_FacingDirection;
	bool m_MovingLeft;
	bool m_MovingRight;
	float m_JumpForce;
	bool m_Jumping;
	bool m_CanJump;
};

