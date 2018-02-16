#pragma once
#include <string>
#include <iostream>
#include "Inventory.h"


class Actor :  public Inventory{
private:
	int mMaxHealth;
	int mHealth;
public:
	Actor();
	Actor(char*,int,int);
	void TakeDamage(int);
	void GiveDamage(Actor*,int);
	void SetName(const std::string&);
	std::string mName;
	int *currentHealth = &mHealth;

public:
	Inventory inventory;
	void GiveItem(Actor*, Item*);
};

