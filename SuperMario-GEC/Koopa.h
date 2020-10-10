#pragma once
#include "Character.h"
#include "SDL.h"


class Koopa : public Character
{
public:

	Koopa(SDL_Renderer* Renderer, string imagePath, Vector2f startPosition, LevelMap* map, FACING startFacing, float movementSpeed);
	~Koopa();
	
	void TakeDamage();
	void Jump();
	void Render();
	void Update(float deltaTime, SDL_Event e);
	Vector2f GetPosition();
	//float GetCollisionRadius();
	//Rectf GetCollisionBox();
	bool GetAlive();
	void SetAlive(bool state);
	bool GetInjured();

protected:



private:

	ENEMY_STATE m_EnemyState;
	void FlipRightWayUp();	
	float m_SingleSpriteWidth;
	float m_SingleSpriteHeight;
	float m_InjuredTime;
	float m_MovementSpeed;
	bool m_Injured;
	FACING m_FacingDirection;
	float m_JumpForce;
	bool m_Jumping;
	bool m_CanJump;
	bool m_MovingLeft;
	bool m_MovingRight;
};

