#pragma once

#include "Player.h"

class Item
{
private:
	virtual void init(Player& object) = 0;

public:
	int price;
	bool available;
	
	void buy(int& money, Player& object);
	Item(int price);

};

