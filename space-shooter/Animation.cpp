#include "Animation.h"
#include <iostream>

Animation::Animation(Texture* texture, Vector2u image_count, float switch_time)
{
	frame_clock = Clock();
	this->image_count = image_count;
	this->switch_time = switch_time;
	current_image.x = 0;

	frame_rect.width  = texture->getSize().x / float(image_count.x);
	frame_rect.height = texture->getSize().y / float(image_count.y);
}

IntRect Animation::getRect()
{
	return frame_rect;
}

void Animation::update()
{
	if (frame_clock.getElapsedTime().asMilliseconds() >= switch_time)
	{
		std::cout << current_image.x << std::endl;
		frame_clock.restart();
		++current_image.x;
		if (current_image.x > image_count.x - 1)
		{
			current_image.x = 0;
		}
	}
	frame_rect.left   = current_image.x * frame_rect.width;
}