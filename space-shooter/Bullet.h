#pragma once
#ifndef BULLET
#define BULLET

#include "BigMeteorite.h"
#include "SmallMeteorite.h"

#include <SFML/Graphics.hpp>
using namespace sf;

class Bullet
{
	friend class Player;

private:
	const float WIDTH = 3.f;
	const float HEIGHT = 3.f;
	float speed;
	float rotation;
	int state;
	const Vector2f dimensions = Vector2f(WIDTH, HEIGHT);

public:
	Bullet(Vector2f player_pos, float rot);

	static Time cooldown;
	Vector2f destination;
	RectangleShape body;

	Vector2f getPosition();
	RectangleShape getSprite();
	void setPosition(Vector2f new_pos);
	void setState(int new_state);

	void move();
	void collision(vector<BigMeteorite> &big_meteorite, vector<SmallMeteorite> &small_meteorites);
};




#endif // !BULLET
