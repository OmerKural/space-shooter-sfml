#include "Coin.h"


Coin::Coin(Texture* texture, Vector2f position) : 
	animation(texture, Vector2u(4, 1), 150.f)
{
	this->position = position;
	sprite.setTexture(*texture);
	sprite.setPosition(position);
}

void Coin::updateSprite()
{
	animation.update();
	sprite.setTextureRect(animation.getRect());
}
Sprite Coin::getSprite()
{
	return sprite;
}