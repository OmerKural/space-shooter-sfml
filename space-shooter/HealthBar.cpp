#include "HealthBar.h"

// constructors
HealthBar::HealthBar(const char* path_to_file)
{
	state = 1;
	hb_pos = Vector2f(10.f, 10.f);

	if (!hbt.loadFromFile(path_to_file)) cout << "Couldn't load " << path_to_file << endl;
	hbs = Sprite(hbt);
	hbs.setPosition(hb_pos);
}

// getters and setters
Sprite HealthBar::getSprite()
{
	return hbs;
}
int HealthBar::getState()
{
	return state;
}
void HealthBar::setState(int new_state)
{
	state = new_state;
}
