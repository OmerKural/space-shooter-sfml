#include "Bullet.h"
#include "Player.h"
#include "Engine.h"
#include "Meteorite.h"
#include "BigMeteorite.h"
#include "SmallMeteorite.h"

#include <iostream>
#include <vector>
using namespace std;

float Bullet::cooldown = 500.f;

Bullet::Bullet(Vector2f player_pos, float rot)
{
	speed = 15.f;
	state = 0;
	body = RectangleShape(dimensions);
	body.setFillColor(Color::White);
	body.setPosition(player_pos);
	rotation = rot - 90.f;
}

Vector2f Bullet::getPosition()
{
	return this->body.getPosition();
}
RectangleShape Bullet::getSprite()
{
	return this->body;
}
void Bullet::setPosition(Vector2f new_pos)
{
	this->body.setPosition(new_pos);
}
void Bullet::setState(int new_state)
{
	state = new_state;
}

void Bullet::move()
{
	if (state == 0)
	{
		const float PI = float(3.14159265);
		Vector2f pos = Vector2f(
			this->getPosition().x + cos(rotation * PI / 180) * speed,
			this->getPosition().y + sin(rotation * PI / 180) * speed
		);
		this->body.setPosition(pos);
	}
	else if (state == 1)
	{
		body.setFillColor(Color::Black);
		body.setPosition(INFINITY, INFINITY);
		state = -1;
	}
}
void Bullet::collision(Player& player,
					   vector<BigMeteorite>& big_meteorites,
					   vector<SmallMeteorite>& small_meteorites,
					   vector<Coin>& coins, Texture* coin_texture)
{
	for (auto& m : big_meteorites)
	{
		if (body.getGlobalBounds().intersects(m.getSprite().getGlobalBounds()))
		{
			player.setPoints(player.getPoints() + BigMeteorite::points);
			coins.push_back(Coin(coin_texture, m.getPosition()));
			small_meteorites.emplace_back(SmallMeteorite(m.getPosition(), m.getDirection()));
			small_meteorites.emplace_back(SmallMeteorite(m.getPosition(), m.getDirection() + 180.f));
			m.setState(1);
			this->setState(1);
			break;
		}
	}
	for (auto& m : small_meteorites)
	{
		if (body.getGlobalBounds().intersects(m.getSprite().getGlobalBounds()))
		{
			player.setPoints(player.getPoints() + SmallMeteorite::points);
			m.setState(1);
			this->setState(1);
			break;
		}
	}
}