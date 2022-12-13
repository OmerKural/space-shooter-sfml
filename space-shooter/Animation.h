#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

class Animation
{
protected:
	Vector2u image_count;
	Vector2u current_image;
	Clock frame_clock;
	float switch_time;

public:
	IntRect frame_rect;
	// constructors
	Animation(Texture* texture, Vector2u image_count, float switch_time);

	// getters and setters
	IntRect getRect();

	// updaters
	void update();
};

