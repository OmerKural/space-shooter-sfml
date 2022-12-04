#include "Engine.h"
#include "Player.h"

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
	// Main Loop
	while (window.isOpen())
	{

		//Update
		update();
		player.turnToCursor(Mouse::getPosition(window));

		//Draw
		window.clear();

		window.draw(player.getSprite());

		window.display();
	
	}
}
