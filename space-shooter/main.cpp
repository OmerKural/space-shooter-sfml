#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Bullet.h"

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(800, 600), "Space Shooter");
	window.setFramerateLimit(60);

	CircleShape triangle(20.f);
	triangle.setPointCount(3);
	triangle.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);
	triangle.setFillColor(Color::Black);
	triangle.setOutlineThickness(2.f);
	triangle.setOutlineColor(Color::White);

	RectangleShape bullet(Vector2f(3.f, 5.f));
	bullet.setPosition(10.f, 10.f);

	float tri_xpos = triangle.getPosition().x, tri_ypos = triangle.getPosition().y;
	const float speed = 10.f;

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) window.close();
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::W)) tri_ypos -= speed;
		if (Keyboard::isKeyPressed(Keyboard::A)) tri_xpos -= speed;
		if (Keyboard::isKeyPressed(Keyboard::S)) tri_ypos += speed;
		if (Keyboard::isKeyPressed(Keyboard::D)) tri_xpos += speed;



		// update state
		triangle.setPosition(tri_xpos, tri_ypos);

		// draw on window screen
		window.clear();
		window.draw(triangle);
		window.draw(bullet);

		window.display();


	}


    return 0;
}
