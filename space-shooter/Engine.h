#pragma once
#ifndef ENGINE
#define ENGINE

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;

class Engine
{
	friend class Player;

private:
	const unsigned int FPS = 60;
	const char* TITLE = "Space Shooter";

	Vector2u resolution;
	Event event;

public:
	static const unsigned int WIDTH = 800;
	static const unsigned int HEIGHT = 600;

	RenderWindow window;
	Engine();

	void run();
};


#endif // !ENGINE