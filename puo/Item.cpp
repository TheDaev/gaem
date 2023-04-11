#include "Item.h"
#include "Player.h"

void Item::buy(int& money, Player& object)
{
	money -= price;
	init(object);
	available = false;
}

Item::Item(int price)
{
	this->price = price;
	this->available = true;
}
