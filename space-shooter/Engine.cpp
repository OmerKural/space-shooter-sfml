#include "Engine.h"
#include "Player.h"
#include "Bullet.h"
#include "BigMeteorite.h"
#include "SmallMeteorite.h"

#include <vector>
#include <iostream>
using namespace std;

Engine::Engine()
{
	resolution = Vector2u(WIDTH, HEIGHT);
	window.create(VideoMode(resolution.x, resolution.y), TITLE, Style::Default);
	window.setFramerateLimit(FPS);
	event = Event();
}

void Engine::run()
{
	Player player;
	vector<Bullet> bullets;
	vector<BigMeteorite> big_meteorites;
	vector<SmallMeteorite> small_meteorites;

	for (int i = 0; i < 3; i++) big_meteorites.emplace_back(BigMeteorite(i));

	//Initializing cooldown clock.
	Clock cooldown;

	// Main Loop
	while (window.isOpen())
	{
		//Controls
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed ||
				(event.type == Event::KeyPressed && event.key.code == Keyboard::Escape))
				window.close();

			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space && 
				cooldown.getElapsedTime() >= Bullet::cooldown)
			{
				// Resetting cooldown clock.
				cooldown = Clock();
				bullets.emplace_back(Bullet(player.getPosition(), player.getSprite().getRotation()));
			}
		}

		// WASD
		if (Keyboard::isKeyPressed(Keyboard::W))
			player.setPosition(Vector2f(player.getPosition().x, player.getPosition().y - Player::speed));
		if (Keyboard::isKeyPressed(Keyboard::A))
			player.setPosition(Vector2f(player.getPosition().x - Player::speed, player.getPosition().y));
		if (Keyboard::isKeyPressed(Keyboard::S))
			player.setPosition(Vector2f(player.getPosition().x, player.getPosition().y + Player::speed));
		if (Keyboard::isKeyPressed(Keyboard::D))
			player.setPosition(Vector2f(player.getPosition().x + Player::speed, player.getPosition().y));

		//Update
		player.turnToCursor(Mouse::getPosition(window));
		for (auto& b : bullets) 
		{
			b.update();
			for (auto& m : big_meteorites)
			{
				if (b.getSprite().getGlobalBounds().intersects(m.getSprite().getGlobalBounds()))
				{
					small_meteorites.emplace_back(SmallMeteorite(m.getPosition(), m.getDirection()));
					small_meteorites.emplace_back(SmallMeteorite(m.getPosition(), m.getDirection()+180.f));
					m.setState(1);
					b.setState(1);
					break;
				}
			}
			for (auto& m : small_meteorites)
			{
				if (b.getSprite().getGlobalBounds().intersects(m.getSprite().getGlobalBounds()))
				{
					m.setState(1);
					b.setState(1);
					break;
				}
			}
		}
		for (auto& m : big_meteorites) m.updateAI();
		for (auto& m : small_meteorites) m.updateAI();

		//Draw
		window.clear();

		window.draw(player.getSprite());
		for (auto& b : bullets) window.draw(b.getSprite());
		for (auto& m : big_meteorites) window.draw(m.getSprite());
		for (auto& m : small_meteorites) window.draw(m.getSprite());

		window.display();
	}
	// end Main Loop
}
