#include "Inventory.h"
#include <iostream>
#include "templates.h"

void Inventory::PrintInventory(std::string name) {
	std::cout << name << "'s Inventory:";
	std::cout << "\n**********************************************************" << std::endl;
	for (int it = 0; it < items.size(); it++) {
		for (const auto& i : items) {
			std::cout << "(" << (it + 1) << ")";
			it++;
			std::cout << " Name: " << i->mName << std::endl;
		}
	}
	std::cout << "**********************************************************" << std::endl;
}

void Inventory::ReceiveItem(Item *item) {
	items.push_back(item);
}

Item* Inventory::TakeItem(int num) {
	Item* answer = items[num -1];
	items.erase(items.begin() + (num - 1));
	return answer;
}

