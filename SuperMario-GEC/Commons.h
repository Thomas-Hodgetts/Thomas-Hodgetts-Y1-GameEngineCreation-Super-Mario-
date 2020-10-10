#pragma once
#include "Helper.h"
#include <vector>
#include <iostream>
#include <ctime>

#define MAP_HEIGHT  13
#define MAP_WIDTH  16
#define TILE_HEIGHT 32
#define TILE_WIDTH 32
#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080 
#define SCREENSHAKE_DURATION 0.25
#define INJURE_TIME 2.5f
#define ANIMATION_DELAY 0.5

#define GRAVITY 96.f;

using namespace helper;
using namespace std;

const float JUMP_FORCE_DECREMENT = 400.f;
const float INITIAL_JUMP_FORCE = 400.f;
const float gravityStrength = 40.f;

enum SCREENS
{
	SCREEN_INTRO = 0,
	SCREEN_MENU,
	SCREEN_LEVEL1,
	SCREEN_LEVEL2,
	SCREEN_GAMEOVER,
	SCREEN_HIGHSCORES

};

enum FACING
{
	FACING_LEFT = 0,
	FACING_RIGHT
};

enum CHARACTER_STATE
{
	CHARCTERSTATE_PLAYER_DEATH = 0,
	CHARCTERSTATE_PLAYER_ALIVE
};

enum ENEMY_STATE
{
	ENEMY_DEATH = 0,
	ENEMY_ALIVE
};

enum COIN_STATE
{
	COIN_AVAILABLE = 0,
	COIN_UNAVAILABLE
};