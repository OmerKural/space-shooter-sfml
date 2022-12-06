#include "BigMeteorite.h"
#include "Engine.h"

vector<Vector2f> BigMeteorite::spawns
{
	{0, 0},                {Engine::WIDTH/2, 0},              {Engine::WIDTH, 0}, 
	{0, Engine::HEIGHT/2},                                    {Engine::WIDTH, Engine::HEIGHT/2},
	{0, Engine::HEIGHT},   {Engine::WIDTH/2, Engine::HEIGHT}, {Engine::WIDTH, Engine::HEIGHT}
};

Vector2f BigMeteorite::ubounds = Vector2f(float(Engine::WIDTH) + 50.f, float(Engine::HEIGHT) + 50.f);
float BigMeteorite::lbounds = -50.f;

BigMeteorite::BigMeteorite(int spawn)
{
	speed = 5.f;
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

	random_shuffle(spawns.begin(), spawns.end());
	body.setPosition(spawns[spawn]);

	int r = rand() % 360;
	body.setRotation(r);

	// Calculate the direction
	const float PI = 3.14159265;
	float dy = Engine::HEIGHT / 2 - body.getPosition().y;
	float dx = Engine::WIDTH  / 2 - body.getPosition().x;
	direction = atan2(dy, dx) * 180 / PI;
}

ConvexShape BigMeteorite::getSprite()
{
	return body;
}

Vector2f BigMeteorite::getPosition()
{
	return body.getPosition();
}

float BigMeteorite::getDirection()
{
	return direction;
}

void BigMeteorite::setState(int new_state)
{
	state = new_state;
}

void BigMeteorite::updateAI()
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