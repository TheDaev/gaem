#pragma once

#include <raylib.h>

class Block
{
public:
	Rectangle body;
	Texture2D texture;
	void Draw();
	void t_Draw();
	Block(Vector2 o_pos, Texture2D texture);
};

