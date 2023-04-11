#include "Block.h"

#include <raylib.h>

void Block::Draw() {
	DrawRectangleRec(body, YELLOW);
}

void Block::t_Draw() {
	DrawTexture(texture, body.x, body.y, WHITE);

}

Block::Block(Vector2 o_pos, Texture2D texture) {
	this->body.x = o_pos.x;
	this->body.y = o_pos.y;

	this->texture = texture;

	body.width = 25;
	body.height = 25;
}