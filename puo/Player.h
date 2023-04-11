#pragma once

#include <raylib.h>
#include <vector>

#include "Item.h"

class Player
{
public:
	Rectangle body;
	Texture2D texture;
	std::vector<Item> items;
	int speed;
	void Update(float dt);
	void Draw();
	void t_Draw();
	Player(Vector2 pos, Vector2 c_size, Texture2D texture, std::vector<Item> items);

};

