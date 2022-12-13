#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;

class Engine
{
private:
	const unsigned int FPS = 60;
	const char* TITLE = "Space Shooter";

	Vector2u resolution;
	Event event;

public:
	static const unsigned int WIDTH = 800;
	static const unsigned int HEIGHT = 600;

	Texture coin_texture;
	Texture health_bar_texture;
	RenderWindow window;

	Engine();

	void run();
	void loadTextures();
};