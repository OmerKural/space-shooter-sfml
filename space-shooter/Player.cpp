#include "Player.h"
#include "Bullet.h"
#include "Engine.h"

#include <iostream>

Player::Player()
{
	speed = 10.f;

	start_pos = Vector2f(Engine::WIDTH/2.f, Engine::HEIGHT / 2.f);
	position = Vector2f(start_pos.x, start_pos.y);

	body = ConvexShape(3);
	body.setPoint(0, Vector2f(0.f, -10.f));
	body.setPoint(1, Vector2f(-10.f, 10.f));
	body.setPoint(2, Vector2f(10.f, 10.f));
	body.setPosition(start_pos);
	body.setFillColor(Color::Black);
	body.setOutlineThickness(1.f);
	body.setOutlineColor(Color::White);
}

ConvexShape Player::getSprite()
{
	return this->body;
}

Vector2f Player::getPosition()
{
	return this->body.getPosition();
}

void Player::setPosition(Vector2f new_pos)
{
	this->body.setPosition(new_pos);
}

void Player::turnToCursor(Vector2i mouse_pos)
{
	const float PI = 3.14159265;
	float dx = this->getPosition().x - mouse_pos.x;
	float dy = this->getPosition().y - mouse_pos.y;
	float rotation = atan2(dy, dx) * 180 / PI + 270.f;
	this->body.setRotation(rotation);
}

void Player::shoot(float rot)
{
	Bullet bullet(this->position, rot);
}