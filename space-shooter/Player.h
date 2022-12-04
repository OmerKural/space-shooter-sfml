#pragma once
#ifndef PLAYER
#define PLAYER

#include <SFML/Graphics.hpp>
using namespace sf;

class Player
{
private:
	const float radius = 20.f;
	float speed;

public:
	Player();
};



#endif // !PLAYER
