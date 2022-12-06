#include "Engine.h"
#include "Player.h"
#include "Bullet.h"

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

	//Initializing cooldown clock.
	Clock clock;

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
				clock.getElapsedTime() >= Bullet::cooldown)
			{
				// Resetting cooldown clock.
				clock = Clock();
				Bullet x = Bullet(player.getPosition(), player.getSprite().getRotation());
				bullets.emplace_back(x);
			}
		}
		// wasd
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
		for (auto& b : bullets) b.update();

		//Draw
		window.clear();

		window.draw(player.getSprite());
		for (auto& b : bullets) window.draw(b.getSprite());

		window.display();
	
	}
}
