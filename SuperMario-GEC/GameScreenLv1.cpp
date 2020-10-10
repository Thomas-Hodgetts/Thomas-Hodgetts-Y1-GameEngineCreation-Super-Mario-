#include "GameScreenLv1.h"
#include <iostream>
#include "Texture2D.h"
#include "MarioCharacter.h"
#include "LuigiCharacter.h"
#include "LevelMap.h"
#include "POW_Block.h"
#include "Koopa.h"

GameScreenLv1::GameScreenLv1(SDL_Renderer* renderer) : GameScreen(renderer)
{
	SetUpLevel(renderer);
	Render();
	SetTime(20);
}


GameScreenLv1::~GameScreenLv1()
{
	delete m_LevelBackgroundTexture;
	m_LevelBackgroundTexture = NULL;
	delete Mario;
	delete Luigi;
	delete POW;
	POW = NULL;
	Mario = NULL;
	Luigi = NULL;
	delete m_LevelMap;
	m_LevelMap = NULL;
	m_Enemies.clear();

}

void GameScreenLv1::Update(float deltaTime, SDL_Event ScreenEvent)
{
	Mario->Update(deltaTime, ScreenEvent);
	Luigi->Update(deltaTime, ScreenEvent);
	UpdateEnemies(deltaTime, ScreenEvent);
	if (Collision::Instance()->Circle(Mario, Luigi))
	{
		cout << "Circle collison" << endl;
	}
	if (Collision::Instance()->Box(Mario->GetCollisionBox(), Luigi->GetCollisionBox()))
	{
		cout << "Box collison" << endl;
	}
	UpdatePOWBlock();
	if (m_screenShake)
	{
		m_screenShakeTime -= deltaTime;
		m_BackgroundYPos *= 3.f;
		if (m_screenShakeTime <= 0.f)
		{
			m_screenShake = false;
			m_BackgroundYPos = 0.0f;
		}
	}
	if (ResetTime())
	{
		CreateKoopa(Vector2f(150.f, 32.f), FACING_RIGHT, 1.f);
		SetTime(20);
	}
	else
	{
		CountTime();
	}
	Render();
}

void GameScreenLv1::UpdatePOWBlock()
{
	if (Collision::Instance()->Box(Mario->GetCollisionBox(), POW->GetCollisionBox()))
	{
		if (POW->IsAvailable())
		{
			if (Mario->IsJumping())
			{
				DoScreenShake();
				POW->TakeAHit();
				Mario->CancelJump();
			}
		}
	}
}
void GameScreenLv1::Render()
{
	m_LevelBackgroundTexture->Render(Vector2f(0, m_BackgroundYPos), SDL_FLIP_NONE);
	Mario->Render();
	Luigi->Render();
	for (unsigned int i = 0; i < m_Enemies.size(); i++)
	{
		m_Enemies[i]->Koopa::Render();
	}
	POW->Render();
	
}
bool GameScreenLv1::SetUpLevel(SDL_Renderer* renderer)
{
	m_LevelBackgroundTexture = new Texture2D(renderer);
	if (!m_LevelBackgroundTexture->LoadFromFile("Images/BackgroundMB.bmp"))
	{
		std::cout << "Failed to load Texture!" << std::endl;
		return false;
	}
	SetLevelUp();
	Mario = new MarioCharacter(renderer, "Images/Mario.bmp", Vector2f(44.f, 230.f), m_LevelMap);
	Luigi = new LuigiCharacter(renderer, "Images/Luigi.bmp", Vector2f(100.f, 230.f), m_LevelMap); //64
	POW = new POW_Block(renderer, m_LevelMap);
	CreateKoopa(Vector2f(64.f, 230.f), FACING_RIGHT, 1.f);
	CreateKoopa(Vector2f(325.f, 32.f), FACING_RIGHT, 1.f);
}

void GameScreenLv1::SetLevelUp()
{
	int map[MAP_HEIGHT][MAP_WIDTH] = { {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
									   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
									   {1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1},
									   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
									   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
									   {0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0},
									   {1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
									   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
									   {0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},
									   {1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1},
									   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
									   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
									   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} };

	if (m_LevelMap != NULL)
	{
		delete m_LevelMap;
	}
	m_LevelMap = new LevelMap(map);
	m_screenShake = false;
	m_BackgroundYPos = 0.f;
 }

void GameScreenLv1::DoScreenShake()
{
	m_screenShake = true;
	m_screenShakeTime = SCREENSHAKE_DURATION;
	m_wobble = 0.0f;
	for (unsigned int i = 0; i < m_Enemies.size(); i++)
	{
		m_Enemies[i]->TakeDamage();
	}
}

void GameScreenLv1::UpdateEnemies(float deltaTime, SDL_Event e)
{
	if (!m_Enemies.empty())
	{
		int enemyIndexToDelete = -1;
		for (unsigned int i = 0; i < m_Enemies.size(); i++)
		{
			if (m_Enemies[i]->GetPosition().Y > 300.f)
			{
				if (m_Enemies[i]->GetPosition().X < (float)(-m_Enemies[i]->GetCollisionBox().Width * 0.5f) || m_Enemies[i]->GetPosition().X > SCREEN_WIDTH - (float)(m_Enemies[i]->GetCollisionBox().Width * 0.55f)) m_Enemies[i]->SetAlive(false);
			}

			m_Enemies[i]->Update(deltaTime, e);

			if ((m_Enemies[i]->GetPosition().Y > 300.f || m_Enemies[i]->GetPosition().Y <= 64.f) && (m_Enemies[i]->GetPosition().X < 64.f || m_Enemies[i]->GetPosition().X > SCREEN_WIDTH - 96.f))
			{

			}
			else
			{
				if (Collision::Instance()->Circle(m_Enemies[i], Mario))
				{
					Mario->SetState(SetCharacterState(0));
				}
			}
			if (m_Enemies[i]->GetInjured())
			{
				if (Collision::Instance()->Circle(m_Enemies[i], Mario))
				{
					m_Enemies[i]->SetAlive(false);
				}
			}
			if (!m_Enemies[i]->GetAlive())
			{
				enemyIndexToDelete = i;
			}
		}
		if (enemyIndexToDelete != -1)
		{
			m_Enemies.erase(m_Enemies.begin() + enemyIndexToDelete);
		}
	}



}

void GameScreenLv1::CreateKoopa(Vector2f position, FACING direction, float speed)
{
	Koopa* _m_koopa = new Koopa(m_ScreenRender, "Images/Koopa.bmp", position, m_LevelMap, direction, speed);
	m_Enemies.push_back(_m_koopa);
	//delete _m_koopa;
}



void GameScreenLv1::SetTime(int Time)
{
	m_TimeTillKoopa = 0;
	m_TimeToSpawnKoopa = Time;
}

bool GameScreenLv1::ResetTime()
{
	if (m_TimeTillKoopa > m_TimeToSpawnKoopa)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void GameScreenLv1::CountTime()
{
	time_t currentTime;
	time(&currentTime);
	if (m_PastTime == NULL)
	{
		m_PastTime = currentTime;
		return;
	}
	m_TimeTillKoopa = difftime(m_PastTime, currentTime);
	m_PastTime = currentTime;
}


CHARACTER_STATE GameScreenLv1::SetCharacterState(int EnuNum)
{
	switch (EnuNum)
	{
	case 0:
		return CHARCTERSTATE_PLAYER_DEATH;
	case 1:
		return CHARCTERSTATE_PLAYER_ALIVE;
	};
}