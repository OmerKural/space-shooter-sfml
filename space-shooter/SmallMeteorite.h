#pragma once
#ifndef SMALL_METEORITE
#define SMALL_METEORITE

#include "Meteorite.h"

#include <SFML/Graphics.hpp>
using namespace sf;

class SmallMeteorite :public Meteorite
{
public:
	// constructors
	SmallMeteorite(Vector2f spawn_pos, float parent_direction);
};

#endif // !SMALL_METEORITE