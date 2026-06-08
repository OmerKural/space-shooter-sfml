#include "HealthBar.h"

int HealthBar::health_bar_count = 4;

HealthBar::HealthBar(Texture* texture)
{
	this->texture = *texture;
	state_rect.width  = texture->getSize().x;
	state_rect.height = texture->getSize().y / float(health_bar_count);
	sprite.setTexture(*texture);
	sprite.setTextureRect(state_rect);
	sprite.setPosition(10.f, 10.f);
	sprite.setScale(1.2f, 1.2f);
}

Sprite HealthBar::getSprite()
{
	return sprite;
}

void HealthBar::increase()
{
	state_rect.top = std::max(
		0,
		state_rect.top - state_rect.height
	);
	sprite.setTextureRect(state_rect);
}
void HealthBar::decrease()
{
	state_rect.top = std::min(
		int(texture.getSize().y - state_rect.height),
		state_rect.top + state_rect.height
	);
	sprite.setTextureRect(state_rect);
}
