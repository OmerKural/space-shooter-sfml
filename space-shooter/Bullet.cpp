#include "Bullet.h"
#include "Player.h"

#include <iostream>
using namespace std;

int Bullet::count = 0;

Bullet::Bullet(Vector2f pos, Vector2f dest)
{
	count++; cout << count << endl;
	speed = 100.f;
	destination = dest;
	body = RectangleShape(dimensions);
	body.setPosition(pos);
}

Bullet::~Bullet()
{
	
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
	this->body.setPosition(Vector2f(this->getPosition().x + 20, this->getPosition().y + 20));
}