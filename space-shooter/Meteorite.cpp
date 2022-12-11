#include "Meteorite.h"
#include "Engine.h"

// statics
vector<Vector2f> Meteorite::spawns
{
	{0, 0},                {Engine::WIDTH / 2, 0},              {Engine::WIDTH, 0},
	{0, Engine::HEIGHT / 2},                                    {Engine::WIDTH, Engine::HEIGHT / 2},
	{0, Engine::HEIGHT},   {Engine::WIDTH / 2, Engine::HEIGHT}, {Engine::WIDTH, Engine::HEIGHT}
};
Vector2f Meteorite::ubounds = Vector2f(float(Engine::WIDTH) + 50.f, float(Engine::HEIGHT) + 50.f);
float Meteorite::lbounds = -50.f;

// constructors
Meteorite::Meteorite()
{
	speed = 5.f;
	state = 0;

	// Calculate the direction
	const float PI = 3.14159265;
	float dy = Engine::HEIGHT / 2 - body.getPosition().y;
	float dx = Engine::WIDTH / 2 - body.getPosition().x;
	direction = atan2(dy, dx) * 180 / PI;
}

// getters and setters
ConvexShape Meteorite::getSprite()
{
	return body;
}
Vector2f Meteorite::getPosition()
{
	return body.getPosition();
}
float Meteorite::getDirection()
{
	return direction;
}
int Meteorite::getState()
{
	return state;
}
void Meteorite::setState(int new_state)
{
	state = new_state;
}

// updaters
void Meteorite::updateAI()
{
	if (state == 0)
	{
		if (body.getPosition().y > ubounds.y) body.setPosition(body.getPosition().x, lbounds);
		else if (body.getPosition().y < lbounds) body.setPosition(body.getPosition().x, ubounds.y);
		else if (body.getPosition().x > ubounds.x) body.setPosition(lbounds, body.getPosition().y);
		else if (body.getPosition().x < lbounds) body.setPosition(ubounds.x, body.getPosition().y);
		else body.move(cos(direction) * speed, sin(direction) * speed);
		body.rotate(1.f);
	}
	else if (state == 1)
	{
		body.setFillColor(Color::Black);
		body.setPosition(INFINITY, INFINITY);
	}
}