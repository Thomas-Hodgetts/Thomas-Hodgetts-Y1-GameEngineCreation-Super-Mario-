#pragma once
#include "Character.h"

class Texture2D;

class Coin : public Character
{
public:

	Coin(SDL_Renderer* Renderer, string imagePath, Vector2f startPosition, LevelMap* map, FACING startFacing);
	~Coin();
	void Render();
	void Update(float deltaTime, SDL_Event e);
	Vector2f GetPosition();
	//float GetCollisionRadius();
	//Rectf GetCollisionBox();
	bool GetAlive();
	void SetAlive(bool state);
	void CollectCoin();

private:

	float m_SingleSpriteWidth;
	float m_SingleSpriteHeight;
	float m_FrameDelay;
	int m_CurrentFrame;
	bool m_MovingLeft;
	bool m_MovingRight;
	FACING m_FacingDirection;
	COIN_STATE m_State;

};

