#include "SmallMeteorite.h"

SmallMeteorite::SmallMeteorite(Vector2f spawn_pos, float parent_direction)
{
	speed = 5.f;
	state = 0;
	direction = parent_direction + 45;

	// Draw the shape.
	body = ConvexShape(5);
	body.setPoint(0, Vector2f(10.f, 10.f));
	body.setPoint(1, Vector2f(20.f, 00.f));
	body.setPoint(2, Vector2f(30.f, 20.f));
	body.setPoint(3, Vector2f(25.f, 30.f));
	body.setPoint(4, Vector2f(05.f, 25.f));
	body.setFillColor(Color(0, 0, 0, 0));
	body.setOutlineColor(Color::White);
	body.setOutlineThickness(1.f);

	body.setPosition(spawn_pos);
	
	int r = std::rand() % 360;
	body.setRotation(r);

}