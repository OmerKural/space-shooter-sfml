#pragma once
#ifndef BIG_METEORITE
#define BIG_METEORITE

#include <vector>

using namespace std;

#include <SFML/Graphics.hpp>
using namespace sf;

class BigMeteorite
{
	friend class Bullet;

private:
	static vector<Vector2f> spawns;
	static Vector2f ubounds;
	static float lbounds;
	float speed;
	float direction;
	int state;
	ConvexShape body;

public:
	// constructors
	BigMeteorite(int spawn);

	// getters
	ConvexShape getSprite();
	Vector2f getPosition();
	float getDirection();

	// setters
	void setState(int new_state);

	// updaters
	void updateAI();
};

#endif // !BIG_METEORITE



