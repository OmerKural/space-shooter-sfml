#include "SmallMeteorite.h"
#include "Engine.h"

#include<vector>
using namespace std;

vector<Vector2f> SmallMeteorite::spawns
{
	{0, 0},                {Engine::WIDTH / 2, 0},              {Engine::WIDTH, 0},
	{0, Engine::HEIGHT / 2},                                    {Engine::WIDTH, Engine::HEIGHT / 2},
	{0, Engine::HEIGHT},   {Engine::WIDTH / 2, Engine::HEIGHT}, {Engine::WIDTH, Engine::HEIGHT}
};

Vector2f SmallMeteorite::ubounds = Vector2f(float(Engine::WIDTH) + 50.f, float(Engine::HEIGHT) + 50.f);
float SmallMeteorite::lbounds = -50.f;

SmallMeteorite::SmallMeteorite(Vector2f spawn_pos, float parent_direction)
{
	speed = 5.f;
	state = 0;

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

	int r = rand() % 360;
	body.setRotation(r);

	direction = parent_direction + 45;
}

ConvexShape SmallMeteorite::getSprite()
{
	return this->body;
}

void SmallMeteorite::setState(int new_state)
{
	state = new_state;
}

void SmallMeteorite::updateAI()
{
	if (state == 0)
	{
		if (body.getPosition().y > ubounds.y) body.setPosition(body.getPosition().x, lbounds);
		else if (body.getPosition().y < lbounds) body.setPosition(body.getPosition().x, ubounds.y);
		else if (body.getPosition().x > ubounds.x) body.setPosition(lbounds, body.getPosition().y);
		else if (body.getPosition().x < lbounds) body.setPosition(ubounds.x, body.getPosition().y);
		else body.move(cos(direction) * speed, sin(direction) * speed);
	}
	else if (state == 1)
	{
		body.setFillColor(Color::Black);
		body.setPosition(INFINITY, INFINITY);
	}
}