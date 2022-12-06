#pragma once
#ifndef PLAYER
#define PLAYER

#include <SFML/Graphics.hpp>
using namespace sf;

class Player
{
private:
	Vector2f start_pos;
	ConvexShape body;

public:
	static float speed;
	Vector2f position;

	Player();

	ConvexShape getSprite();
	Vector2f getPosition();
	void setPosition(Vector2f new_pos);
	void shoot(float rot);
	void turnToCursor(Vector2i cursor_pos);
};



#endif // !PLAYER
