#pragma once
#ifndef BIG_METEORITE
#define BIG_METEORITE

#include "Meteorite.h"

#include <SFML/Graphics.hpp>
using namespace sf;

class BigMeteorite :public Meteorite
{
public:
	// constructors
	BigMeteorite(int spawn);
};

#endif // !BIG_METEORITET



