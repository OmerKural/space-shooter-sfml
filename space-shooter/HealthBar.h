#pragma once

#include <iostream>
#include <vector>
using namespace std;

#include <SFML/Graphics.hpp>
using namespace sf;

class HealthBar
{
private:
	int health_bar_height;
	IntRect state_rect;
	Vector2f hb_pos;
	Texture texture;
	Sprite sprite;

public:
	static int health_bar_count;
	
	// constructors
	HealthBar(Texture* texture);

	// getters and setters
	Sprite getSprite();

	// updaters
	void increase();
	void decrease();
};


