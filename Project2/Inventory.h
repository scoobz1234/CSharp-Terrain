#pragma once
#include "Item.h"
#include <vector>

class Inventory : public Item {
public:
	void PrintInventory();
protected:
	std::vector<Item> items;
public:
	Item TakeItem(int);
	void ReceiveItem(Item);
	void Inventory::RemoveItem(int);
};

