#pragma once
#include <string>
#include <iostream>
#include "Inventory.h"


class Actor :  public Inventory{
private:
	int maxHealth;
	int health;
public:
	Actor();
	void TakeDamage(int);
	void GiveDamage(Actor*,int);
	void SetName(const std::string&);
	std::string name;
	int *currentHealth = &health;

public:
	Inventory inventory;
	void GiveItem(Actor*, Item);
};

