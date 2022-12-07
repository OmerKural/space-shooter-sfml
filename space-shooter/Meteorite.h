#pragma once
#ifndef METEORITE
#define METEORITE

#include <vector>
using namespace std;

#include <SFML/Graphics.hpp>
using namespace sf;

class Meteorite
{
	friend class Bullet;

protected:
	static vector<Vector2f> spawns;
	static Vector2f ubounds;
	static float lbounds;
	float speed;
	float direction;
	int state;
	ConvexShape body;
	
public:
	// constructors
	Meteorite();

	// getters
	ConvexShape getSprite();
	Vector2f getPosition();
	float getDirection();
	int getState();

	// setters
	void setState(int new_state);

	// updaters
	void updateAI();
};

#endif // !METEORITE



