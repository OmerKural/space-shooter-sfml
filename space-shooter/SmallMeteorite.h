#pragma once
#ifndef SMALL_METEORITE
#define SMALL_METEORITE

#include <vector>
using namespace std;

#include <SFML/Graphics.hpp>
using namespace sf;

class SmallMeteorite
{
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
	SmallMeteorite(Vector2f spawn_pos, float parent_direction);

	// getters
	ConvexShape getSprite(void);

	// setters
	void setState(int new_state);

	// updaters
	void updateAI(void);
};

#endif // !SMALL_METEORITE



