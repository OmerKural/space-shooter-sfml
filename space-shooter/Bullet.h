#pragma once
#ifndef BULLET
#define BULLET

#include <SFML/Graphics.hpp>
using namespace sf;

class Bullet
{
	friend class Player;

private:

	const float WIDTH = 3.f;
	const float HEIGHT = 5.f;
	float speed;
	const Vector2f dimensions = Vector2f(WIDTH, HEIGHT);

public:
	static int count;
	Bullet(Vector2f, Vector2f);
	~Bullet();

	Vector2f destination;
	RectangleShape body;

	Vector2f getPosition();
	void setPosition(Vector2f new_pos);
	void update();
	RectangleShape getSprite();
};




#endif // !BULLET
