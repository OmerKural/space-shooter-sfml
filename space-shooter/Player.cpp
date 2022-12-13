#include "Player.h"
#include "Bullet.h"
#include "Engine.h"
#include "Meteorite.h"
#include "Coin.h"

// static variable initialisations
int Player::health = 3;
float Player::speed = 5.f;
Clock Player::invincibility_clock = Clock();
Time Player::invincibility_duration = seconds(3);

// constructors
Player::Player()
{
	is_invincible = true;

	start_pos = Vector2f(Engine::WIDTH/2.f, Engine::HEIGHT / 2.f);
	position = Vector2f(start_pos.x, start_pos.y);

	body = ConvexShape(3);
	body.setPoint(0, Vector2f(0.f, -10.f));
	body.setPoint(1, Vector2f(-10.f, 10.f));
	body.setPoint(2, Vector2f(10.f, 10.f));
	body.setPosition(start_pos);
	body.setFillColor(Color::Black);
	body.setOutlineThickness(2.f);
	body.setOutlineColor(Color::White);
}

// getters and setters
ConvexShape Player::getSprite()
{
	return body;
}
Vector2f Player::getPosition()
{
	return body.getPosition();
}
void Player::setPosition(Vector2f new_pos)
{
	body.setPosition(new_pos);
}

// updaters
void Player::decreaseHealth(vector<HealthBar>& health_bar)
{
	// get the last element that has a state of 1 and make it 0.
	for (int i = int(health_bar.size()) - 1; i >= 0; i--)
	{
		if (health_bar[i].getState()) 
		{
			health_bar[i].setState(0);
			break;
		}
	}
}
void Player::increaseHealth(vector<HealthBar>& health_bar)
{
	// get the first element that has a state of 0 and make it 1.
	for (int i = 0; i < health_bar.size(); i++)
	{
		if (!health_bar[i].getState())
		{
			health_bar[i].setState(1);
			break;
		}
	}
}
void Player::blink()
{
	if (is_invincible && invincibility_clock.getElapsedTime() <= invincibility_duration)
	{
		// Makes the player half-transparent
		body.setOutlineColor(Color(255, 255, 255, 50));
	}
	else
	{
		body.setOutlineColor(Color(255, 255, 255, 255));
		is_invincible = false;
	}
}
void Player::input()
{
	if (Keyboard::isKeyPressed(Keyboard::W))
		this->setPosition(Vector2f(this->getPosition().x, this->getPosition().y - speed));
	if (Keyboard::isKeyPressed(Keyboard::A))
		this->setPosition(Vector2f(this->getPosition().x - speed, this->getPosition().y));
	if (Keyboard::isKeyPressed(Keyboard::S))
		this->setPosition(Vector2f(this->getPosition().x, this->getPosition().y + speed));
	if (Keyboard::isKeyPressed(Keyboard::D))
		this->setPosition(Vector2f(this->getPosition().x + speed, this->getPosition().y));
}
void Player::turnToCursor(Vector2i mouse_pos)
{
	const float PI = float(3.14159265);
	float dx = this->getPosition().x - mouse_pos.x;
	float dy = this->getPosition().y - mouse_pos.y;
	float rotation = atan2(dy, dx) * 180 / PI + 270.f;
	body.setRotation(rotation);
}
void Player::updateHealth(vector<BigMeteorite>& big_meteorites, 
	                      vector<HealthBar>& health_bar)
{
	for (auto& m : big_meteorites)
	{
		// collision
		if (invincibility_clock.getElapsedTime() >= invincibility_duration &&
			m.getSprite().getGlobalBounds().intersects(body.getGlobalBounds()))
		{
			decreaseHealth(health_bar);
			--health;
			is_invincible = true;
			invincibility_clock = Clock();
		}
	}
}
void Player::updateHealth(vector<SmallMeteorite>& small_meteorites, 
						  vector<HealthBar>& health_bar)
{
	for (auto& m : small_meteorites)
	{
		//collision
		if (invincibility_clock.getElapsedTime() >= invincibility_duration &&
			m.getSprite().getGlobalBounds().intersects(body.getGlobalBounds()))
		{
			decreaseHealth(health_bar);
			--health;
			is_invincible = true;
			invincibility_clock.restart();
		}
	}
}