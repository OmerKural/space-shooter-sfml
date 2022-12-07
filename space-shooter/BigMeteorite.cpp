#include "BigMeteorite.h"

BigMeteorite::BigMeteorite(int spawn)
{
	state = 0;

	// Draw the shape
	body = ConvexShape(5);
	body.setPoint(0, Vector2f(0, 60));
	body.setPoint(1, Vector2f(30, 80));
	body.setPoint(2, Vector2f(70, 55));
	body.setPoint(3, Vector2f(55, 30));
	body.setPoint(4, Vector2f(20, 20));
	body.setFillColor(Color(0, 0, 0, 0));
	body.setOutlineColor(Color::White);
	body.setOutlineThickness(1.f);

	std::random_shuffle(spawns.begin(), spawns.end());
	body.setPosition(spawns[spawn]);

	int r = std::rand() % 360;
	body.setRotation(r);
}