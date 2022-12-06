#pragma once
#ifndef METEORITE
#define METEORITE

#include <SFML/Graphics.hpp>
using namespace sf;

class Meteorite
{
protected:
	ConvexShape body = ConvexShape(5);

public:
	Meteorite() : body(){}

	ConvexShape getSprite();
	void updateAI();
};

#endif // !METEORITE



