#pragma once

#include "BigMeteorite.h"
#include "SmallMeteorite.h"
#include "HealthBar.h"
#include "Coin.h"

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
	static Clock isInvincible_clock;
	static Clock invincibility_clock;
	static Time isInvincible_interval;
	static Time invincibility_duration;
	
	int points;
	bool is_invincible;

	// updaters
	void decreaseHealth(HealthBar& health_bar);
	void increaseHealth(HealthBar& health_bar);

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
	int getPoints();
	void setPosition(Vector2f new_pos);
	void setPoints(int new_points);

	// updaters
	void input();
	void turnToCursor(Vector2i cursor_pos);
	void isInvincible();
	void updateHealth(vector<BigMeteorite>& big_meteorites, HealthBar& health_bar);
	void updateHealth(vector<SmallMeteorite>& small_meteorites, HealthBar& health_bar);
};
