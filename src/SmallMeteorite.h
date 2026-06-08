#pragma once

#include "Meteorite.h"

#include <SFML/Graphics.hpp>
using namespace sf;

class SmallMeteorite :public Meteorite
{
private:
	float speed;

public:
	// statics
	static const int points = 50;

	// constructors
	SmallMeteorite(Vector2f spawn_pos, float parent_direction);

	// getters and setters
	float getSpeed();
};