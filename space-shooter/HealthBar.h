#pragma once
#ifndef HEALTH_BAR
#define HEALTH_BAR

#include <iostream>
#include <vector>
using namespace std;

#include <SFML/Graphics.hpp>
using namespace sf;

class HealthBar
{
private:
	int state;
	Vector2f hb_pos;
	Texture hbt;
	Sprite hbs;

public:
	// constructors
	HealthBar(const char* path_to_file);

	// getters and setters
	Sprite getSprite();
	int getState();
	void setState(int new_state);
};

#endif // !HEALTH_BAR


