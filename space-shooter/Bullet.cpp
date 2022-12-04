#include "Bullet.h"
#include "Player.h"

#include <iostream>
using namespace std;

Time Bullet::cooldown = seconds(1);

Bullet::Bullet(Vector2f player_pos, float rot)
{
	speed = 15.f;
	cooldown = seconds(1);
	body = RectangleShape(dimensions);
	body.setPosition(player_pos);
	rotation = rot - 90.f;
}

Vector2f Bullet::getPosition()
{
	return this->body.getPosition();
}

void Bullet::setPosition(Vector2f new_pos)
{
	this->body.setPosition(new_pos);
}

RectangleShape Bullet::getSprite()
{
	return this->body;
}

void Bullet::update()
{
	const float PI = 3.14159265;
	Vector2f pos = Vector2f(
		this->getPosition().x + cos(rotation * PI / 180) * speed,
		this->getPosition().y + sin(rotation * PI / 180) * speed
	);
	this->body.setPosition(pos);

}