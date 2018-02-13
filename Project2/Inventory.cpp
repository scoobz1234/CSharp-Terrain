#include "Inventory.h"
#include <iostream>

void Inventory::PrintInventory() {
	for (int it = 0; it < items.size(); it++) {
		for (auto i = items.begin(); i < items.end(); i++) {
			std::cout << "(" << (it+1) << ")";
			it++;
			std::cout << " Name: " << i->name << std::endl;
		}
	}
}

void Inventory::ReceiveItem(Item item) {
	items.push_back(item);
}

Item Inventory::TakeItem(int num) {
	return items[(num -1)];
}

void Inventory::RemoveItem(int num) {
	items.erase(items.begin() + (num -1));

}