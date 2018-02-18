#pragma once
#include "Item.h"
#include <vector>
#include <string>

class Inventory : public Item {
public:
	Inventory() : Item() {}
	void PrintInventory(std::string);
protected:
	std::vector<Item*> items;
public:
	Item* TakeItem(int);
	void ReceiveItem(Item*);
};

