#include "Engine.h"
#include "Player.h"
#include "Bullet.h"
#include "BigMeteorite.h"
#include "SmallMeteorite.h"
#include "HealthBar.h"
#include "Coin.h"

#include <string>

Engine::Engine()
{
	resolution = Vector2u(WIDTH, HEIGHT);
	window.create(VideoMode(resolution.x, resolution.y), TITLE, Style::Default);
	window.setFramerateLimit(FPS);
	event = Event();
}

void Engine::run()
{
	loadTextures();

	int meteorite_count = 5;
	HealthBar health_bar = HealthBar(&health_bar_texture);
	Player player;
	vector<Coin> coins;
	vector<Bullet> bullets;
	vector<BigMeteorite> big_meteorites;
	vector<SmallMeteorite> small_meteorites;
	Clock bullet_cooldown;

	for (int i = 0; i < meteorite_count; i++) big_meteorites.emplace_back(BigMeteorite(i%9));

	sf::Font font;
	if (!font.loadFromFile("Fonts\\ARCADECLASSIC.ttf"))
	{
		cout << "Couldn't load font" << endl;
	}

	sf::Text point_text;
	point_text.setFont(font);
	point_text.setString("0 Points");
	point_text.setCharacterSize(20);
	point_text.setFillColor(sf::Color::White);
	point_text.setPosition(10, 30);

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
				bullet_cooldown.getElapsedTime().asMilliseconds() >= Bullet::cooldown)
			{
				// Resetting cooldown clock.
				bullet_cooldown.restart();
				bullets.emplace_back(Bullet(player.getPosition(), player.getSprite().getRotation()));
			}
		}

		// WASD
		player.input();

		// Update ------------------------------------
		point_text.setString(to_string(player.getPoints()) + " Points");
		player.turnToCursor(Mouse::getPosition(window));
		player.isInvincible();
		for (auto& c : coins) c.updateSprite();
		for (auto& b : bullets)
		{
			b.move();
			b.collision(player, big_meteorites, small_meteorites, coins, &coin_texture);
		}
		for (auto& m : big_meteorites) m.updateAI();
		for (auto& m : small_meteorites) m.updateAI();
		player.updateHealth(big_meteorites, health_bar);
		player.updateHealth(small_meteorites, health_bar);

		// Draw ---------------------------------------
		window.clear();

		window.draw(point_text);
		window.draw(player.getSprite());
		window.draw(health_bar.getSprite());
		for (auto& c : coins) window.draw(c.getSprite());
		for (auto& b : bullets) window.draw(b.getSprite());
		for (auto& m : big_meteorites) window.draw(m.getSprite());
		for (auto& m : small_meteorites) window.draw(m.getSprite());

		window.display();
	}
	// end Main Loop
}

void Engine::loadTextures()
{
	if (!coin_texture.loadFromFile("Assets\\coin_sheet.png"))
		cout << "Couldn't load Assets\\coin_sheet.png" << endl;
	if (!health_bar_texture.loadFromFile("Assets\\health_bar_sheet.png"))
		cout << "Couldn't load Assets\\health_bar_sheet.png" << endl;
}