#pragma once

#include "Animation.h"

#include <iostream>
#include <vector>
using namespace std;

#include <SFML/Graphics.hpp>
using namespace sf;

class Coin
{
private:
	Animation animation;
	Texture texture;
	Sprite sprite;
	Vector2f position;

public:
	// constructors
	Coin(Texture* texture, Vector2f position);

	// updaters
	void updateSprite();

	// getters and setters
	Sprite getSprite();
};


