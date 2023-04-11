#include <iostream>
#include <string>
#include <vector>

#include "Player.h"
#include "Block.h"

#include "Item.h"
#include "SpeedMul.h"


void respawn(Rectangle& pos) {
	pos.x = GetRandomValue(0, 450);
	pos.y = 0;
}

int main() {
	InitWindow(500, 700, "Puu");
	SetTargetFPS(60);
	SetExitKey(NULL);

	/*STATE
	-0 = PAUSE
	-1 = GAMEz
	-2 = SHOP
	*/

	int state = 0;

	//Textures
	Texture2D p_Texture  = LoadTexture("sprites/player.png");
	Texture2D bl_Texture = LoadTexture("sprites/block.png");
	Texture2D gs_Texture = LoadTexture("sprites/GamePause.png");
	Texture2D bg_Texture = LoadTexture("sprites/BG.png");
	Texture2D sUi_Texture = LoadTexture("sprites/shop_ui2.png");

	//Blocks
	Block* b1 = new Block({ (float)GetRandomValue(0,450),0 }, bl_Texture);
	Block* b2 = new Block({ (float)GetRandomValue(0,450),0 }, bl_Texture);
	Block* b3 = new Block({ (float)GetRandomValue(0,450),0 }, bl_Texture);

	Rectangle r_rec{200,200,200,100};

	
	std::vector<Item> items;
	Player* plr = new Player( { 500 / 2 - 25, 630 }, {50,70}, p_Texture, items );
	

	Block* blocks[3] = {
		b1, b2, b3
	};

	float score = 0;

	while (!WindowShouldClose()) {
		BeginDrawing();

		ClearBackground(RAYWHITE);

		//Pause / Start screen
		if (state == 0) {
			DrawTexture(gs_Texture, 0, 0, WHITE);
			if (IsKeyPressed(KEY_SPACE))
				state = 1;
			else if (IsKeyPressed(KEY_H))
				state = 2;
		}

		//Game loop
		else if (state == 1) {

			if (IsKeyPressed(KEY_ESCAPE))
				state = 0;

			plr->Update(GetFrameTime());

			DrawTexture(bg_Texture, 0, 0, WHITE);

			for (int i = 0; i < 3; i++) {

				if (blocks[i]->body.y > 700) {
					respawn(blocks[i]->body);
				}

				if (CheckCollisionRecs(plr->body, blocks[i]->body)) {
					score += 1;
					respawn(blocks[i]->body);
				}

				blocks[i]->body.y += GetRandomValue(80, 200) * GetFrameTime();

				blocks[i]->t_Draw();
			}

			plr->t_Draw();

			//DrawScore
			//DrawRectangle(0, 0, 100, 90, BROWN);
			DrawText(std::to_string((int)score).c_str(), 10, 0, 50, BLUE);
		}

		//Shop
		else if (state == 2) {
			if (IsKeyPressed(KEY_ESCAPE))
				state = 0;

			DrawTexture(sUi_Texture, 0, 0, WHITE);

			DrawRectangleRec(r_rec, RAYWHITE);


			DrawText(std::to_string((int)score).c_str(), 100,635, 25, GREEN);



		}

		EndDrawing();
	}

	delete plr;

	CloseWindow();

}