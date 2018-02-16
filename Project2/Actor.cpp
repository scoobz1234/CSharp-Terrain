#include "Actor.h"
#include <algorithm>

Actor::Actor(char* name,int maxHealth,int health): mMaxHealth(maxHealth),
mHealth(mHealth),mName(name) {}

void Actor::TakeDamage(int damage) {
	mHealth -= damage;
}

void Actor::GiveDamage(Actor* actor,int damage) {
	actor->mHealth -= damage;
}

void Actor::SetName(const std::string& name) {
	Actor::mName = name;
}

void Actor::GiveItem(Actor* actor, Item* item) {
	actor->inventory.ReceiveItem(item);
}