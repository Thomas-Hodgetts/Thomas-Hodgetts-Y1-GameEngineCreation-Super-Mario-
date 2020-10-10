#pragma once
#include "GameScreen.h"
#include "SDL.h"
#include "Commons.h"
#include "MarioCharacter.h"
#include "LuigiCharacter.h"
#ifndef _GAMESCREENLV1_H
#define _GAMESCREENLV1_H
#endif // _GAMESCREENLV1_H

class Texture2D;
class MarioCharacter;
class LuigiCharacter;
class LevelMap;
class POW_Block;
class Koopa;

class GameScreenLv1 : GameScreen
{
public:
	GameScreenLv1(SDL_Renderer* renderer);
	~GameScreenLv1();
	void Render();
	void Update(float deltaTime, SDL_Event ScreenEvent);
	void UpdatePOWBlock();


private:
	void DoScreenShake();
	void UpdateEnemies(float deltaTime, SDL_Event e);
	void CreateKoopa(Vector2f position, FACING direction, float speed);
	bool SetUpLevel(SDL_Renderer* renderer);
	void SetTime(int Time);
	bool ResetTime();
	void CountTime();
	CHARACTER_STATE SetCharacterState(int EnuNum);
	Texture2D* m_LevelBackgroundTexture;
	MarioCharacter* Mario;
	LuigiCharacter* Luigi;
	POW_Block* POW;
	void SetLevelUp();
	LevelMap* m_LevelMap;
	bool m_screenShake;
	float m_screenShakeTime;
	float m_wobble;
	float m_BackgroundYPos;
	float m_TimeTillKoopa;
	float m_TimeToSpawnKoopa;
	vector<Koopa*> m_Enemies;
	time_t m_PastTime;
};