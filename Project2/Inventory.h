#pragma once
#include "Item.h"
#include <vector>

class Inventory : public Item {
public:
	Inventory() : Item() {}
	void PrintInventory();
protected:
	std::vector<Item*> items;
public:
	Item* TakeItem(int);
	void ReceiveItem(Item*);
};

