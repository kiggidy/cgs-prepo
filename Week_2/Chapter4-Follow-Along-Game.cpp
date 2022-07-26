#include <iostream>
#include <string>

using namespace std;


constexpr int kHeight = 5;
constexpr int kWidth = 6;

template <typename Type>
class Point
{
public:
	Type x;
	Type y;
	Point(Type xVal, Type yVal)
		: x(xVal)
		, y(yVal)
	{

	}
	Type GetLargerCoordinate()
	{
		if (x > y)
		{
			return x;
		}
		else
		{
			return y;
		}
	}
	Type GetSmallerCoordinate()
	{
		if (x < y)
		{
			return x;
		}
		else
		{
			return y;
		}
	}
};


class Character
{
protected:
	float m_Health;
	bool m_IsAlive;
	<Point*> m_pPoint;

public:
	Character(float health, int x, int y)
		: m_pPoint(new Point(x, y))
		, m_Health(health)
		, m_IsAlive(false)
	{

	}

	Character()
	{

	}

	~Character()
	{
		delete m_pPoint;
		m_pPoint = nullptr;
	}

	void Move(int x, int y)
	{
		m_pPoint->x += x;
		m_pPoint->y += y;
	}

	void TakeDamage(float damage)
	{
		if (m_IsAlive)
		{
			m_Health -= damage;
			if (m_Health <= 0)
			{
				m_Health = 0;
				m_IsAlive = false;
			}
		}
	}

	virtual void Draw()
	{
		std::cout << "I'm not sure how to draw myself" << std::endl;
	}
};

class Player : public Character
{
	bool m_HasKey;

public:
	Player(float health, int x, int y)
		: Character(health, x, y)
		, m_HasKey(false)
	{

	}

	Player()
	{

	}

	void Draw() override
	{
		std::cout << "@" << std::endl;
	}

	void UseHealth(float health)
	{
		m_Health += health;
		if (!m_IsAlive)
		{
			m_IsAlive = true;
		}
	}
	void PickupKey()
	{
		m_HasKey = true;
	}
};


class Enemy : public Character
{
	bool m_Strength;

public:
	Enemy(float health, int x, int y, float strength)
		: Character(health, x, y)
		, m_Strength(strength)
	{

	}

	Enemy()
	{

	}

	void Draw() override
	{
		std::cout << "*" << std::endl;
	}
};

int main()
{
	Character character;
	Player player;
	Enemy enemy;

	character.Draw();
	player.Draw();
	enemy.Draw();
}