#pragma once
#ifndef BULLET
#define BULLET

#include <SFML/Graphics.hpp>
using namespace sf;

class Bullet
{
private:
	const float WIDTH = 3.f;
	const float HEIGHT = 5.f;
	const Vector2f dimensions = { WIDTH, HEIGHT };
	float speed;


public:
	Bullet();

	void create(float, float);
};




#endif // !BULLET
