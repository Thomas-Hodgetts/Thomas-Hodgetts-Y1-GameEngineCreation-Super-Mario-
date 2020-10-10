#pragma once
#include "Commons.h"

class Character;


class Collision
{
public:
	~Collision();

	static Collision* Instance();
	bool Circle(Character* character1, Character* character2);
	bool Box(Rectf rect1, Rectf rect2);


private:
	Collision();
	static Collision* m_Instance;

};

