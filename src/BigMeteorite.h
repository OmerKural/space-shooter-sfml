#pragma once

#include "Meteorite.h"

#include <SFML/Graphics.hpp>
using namespace sf;

class BigMeteorite :public Meteorite
{
private:
	float speed;

public:
	// statics
	static const int points = 100;

	// constructors
	BigMeteorite(int spawn);

	// getters and setters
	float getSpeed();
};



