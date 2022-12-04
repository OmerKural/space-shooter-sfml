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

	// Main Loop
	while (window.isOpen())
	{

		//Update
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed ||
				event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
				window.close();

			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space)
			{
				Bullet x = Bullet(Vector2f(player.getPosition()), Vector2f(Mouse::getPosition()));
				bullets.emplace_back(x);
			}
		}

		player.turnToCursor(Mouse::getPosition(window));

		for (Bullet b : bullets)
		{
			b.update();
		}

		//Draw
		window.clear();

		window.draw(player.getSprite());

		for (Bullet b : bullets)
		{
			window.draw(b.getSprite());
		}

		window.display();
	
	}
}
