#include "Engine.h"
#include "Player.h"
#include "Bullet.h"
#include "BigMeteorite.h"
#include "SmallMeteorite.h"
#include "HealthBar.h"

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
	int meteorite_count = 5;

	HealthBar hb0 = HealthBar("Assets\\health_bar_0.png");
	HealthBar hb1 = HealthBar("Assets\\health_bar_1.png");
	HealthBar hb2 = HealthBar("Assets\\health_bar_2.png");
	HealthBar hb3 = HealthBar("Assets\\health_bar_3.png");
	vector<HealthBar> health_bar = { hb0, hb1, hb2, hb3 };
	Player player;
	vector<Bullet> bullets;
	vector<BigMeteorite> big_meteorites;
	vector<SmallMeteorite> small_meteorites;

	for (int i = 0; i < meteorite_count; i++) big_meteorites.emplace_back(BigMeteorite(i%9));

	//Initializing bullet cooldown clock.
	Clock bullet_cooldown;

	// Main Loop
	while (window.isOpen())
	{
		// Controls
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed ||
				(event.type == Event::KeyPressed && event.key.code == Keyboard::Escape))
				window.close();

			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space && 
				bullet_cooldown.getElapsedTime() >= Bullet::cooldown)
			{
				// Resetting cooldown clock.
				bullet_cooldown.restart();
				bullets.emplace_back(Bullet(player.getPosition(), player.getSprite().getRotation()));
			}
		}

		// WASD
		player.input();

		// Update
		player.turnToCursor(Mouse::getPosition(window));
		player.blink();
		for (auto& b : bullets) 
		{
			b.move();
			b.collision(big_meteorites, small_meteorites);
		}
		player.updateHealth(big_meteorites, health_bar);
		player.updateHealth(small_meteorites, health_bar);

		// Draw
		window.clear();
		window.draw(player.getSprite());
		for (auto& b : bullets) window.draw(b.getSprite());
		for (auto& m : big_meteorites) window.draw(m.getSprite());
		for (auto& m : small_meteorites) window.draw(m.getSprite());
		for (auto& b : health_bar) if (b.getState()) window.draw(b.getSprite());

		window.display();
	}
	// end Main Loop
}
