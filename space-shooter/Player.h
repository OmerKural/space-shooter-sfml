#pragma once
#ifndef PLAYER
#define PLAYER

#include "BigMeteorite.h"
#include "SmallMeteorite.h"
#include "HealthBar.h"

#include <vector>
#include <concepts>
#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>
using namespace sf;

class Player
{
private:
	Vector2f start_pos;
	ConvexShape body;
	
	static int health;
	static Clock blink_clock;
	static Clock invincibility_clock;
	static Time blink_interval;
	static Time invincibility_duration;
	
	bool is_invincible;

	// private updaters
	void decreaseHealth(vector<HealthBar>& health_bar);
	void increaseHealth(vector<HealthBar>& health_bar);

public:
	// variables
	Vector2f position;

	// statics
	static float speed;

	// constructors
	Player();

	// getters and setters
	ConvexShape getSprite();
	Vector2f getPosition();
	void setPosition(Vector2f new_pos);

	// updaters
	void input();
	void turnToCursor(Vector2i cursor_pos);
	void blink();
	void updateHealth(vector<BigMeteorite>& big_meteorites, vector<HealthBar>& health_bar);
	void updateHealth(vector<SmallMeteorite>& small_meteorites, vector<HealthBar>& health_bar);
};



#endif // !PLAYER
