#include "Engine.h"
#include "Player.h"

void Engine::update()
{
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed ||
			event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
			window.close();
	}
}