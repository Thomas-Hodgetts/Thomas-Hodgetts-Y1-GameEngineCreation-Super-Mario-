#include "Collision.h"
#include "Character.h"

Collision* Collision::m_Instance = NULL;

Collision::Collision()
{

}

Collision::~Collision()
{
	m_Instance = NULL;
}



Collision* Collision::Instance()
{
	if (!m_Instance)
	{
		m_Instance = new Collision;
	}

	return m_Instance;
}

bool Collision::Circle(Character* character1, Character* character2)
{
	Vector2f vec = Vector2f((character1->GetPosition().X - character2->GetPosition().X), (character1->GetPosition().Y - character2->GetPosition().Y));
	double distance = sqrt((vec.X * vec.X) + (vec.Y * vec.Y));
	double combinedDistance = (character1->GetCollisionRadius() + character2->GetCollisionRadius());
	return distance < combinedDistance;
}

bool Collision::Box(Rectf rect1, Rectf rect2)
{
	if (rect1.X + (rect1.Width / 2) > rect2.X&& rect1.X + (rect1.Width / 2) < rect2.X + rect2.Width && rect1.X + (rect1.Width / 2) > rect2.Y&& rect1.X + (rect1.Width / 2) < rect2.Y + rect2.Height)
	{
		return true;
	}
	return false;
}