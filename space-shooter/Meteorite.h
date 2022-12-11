#pragma once
#ifndef METEORITE
#define METEORITE

#include <vector>
using namespace std;

#include <SFML/Graphics.hpp>
using namespace sf;

class Meteorite
{
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

	// getters and setters
	ConvexShape getSprite();
	Vector2f getPosition();
	float getDirection();
	int getState();
	void setState(int new_state);

	// updaters
	void updateAI();
};

#endif // !METEORITE



