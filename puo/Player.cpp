#include "Player.h"

#include <raylib.h>

void Player::Update(float dt) {

	if (IsKeyDown(KEY_D))
		body.x += speed * dt;
	if (IsKeyDown(KEY_A))
		body.x -= speed * dt;
}

void Player::Draw() {
	DrawRectangleRec(body, BLACK);
}

void Player::t_Draw() {
	DrawTexture(texture, body.x, body.y, WHITE);
}

Player::Player(Vector2 pos, Vector2 c_size, Texture2D texture, std::vector<Item> items)
{
	this->body.x = pos.x;
	this->body.y = pos.y;
	
	this->body.width = c_size.x;
	this->body.height = c_size.y;

	this->texture = texture;
	this->items = items;

	this->speed = 200;

}
