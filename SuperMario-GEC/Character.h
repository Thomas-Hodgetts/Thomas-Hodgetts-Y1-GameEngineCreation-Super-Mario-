#pragma once
#include "SDL.h"
#include "Commons.h"
#include <iostream>

class Texture2D;
class LevelMap;

class Character
{
public:
	
	Character(SDL_Renderer* Renderer, string imagePath, Vector2f startPosition, LevelMap* map);
	~Character();

	virtual void Render();
	virtual inline void Update(float deltaTime, SDL_Event Event);
	void SetPosition(Vector2f newPosition);
	virtual void SetState(CHARACTER_STATE state);
	Vector2f GetPosition();
	float GetCollisionRadius();
	Rectf GetCollisionBox();
	void CancelJump();
	bool IsJumping();


protected:

	SDL_Renderer* m_Renderer;
	Vector2f m_Position;
	Texture2D* m_Texture;
	CHARACTER_STATE m_State;
	virtual void MoveLeft(float deltaTime);
	virtual void MoveRight(float deltaTime);
	void AddGravity(float deltaTime);
	void Jump();
	float m_CollistionRadius;

private: 
	FACING m_FacingDirection;
	bool m_MovingLeft;
	bool m_MovingRight;
	float m_JumpForce;
	bool m_Jumping;
	bool m_CanJump;
	LevelMap* m_CurrentLevelMap;
};

