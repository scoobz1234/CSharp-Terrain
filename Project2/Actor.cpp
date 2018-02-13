#include "Actor.h"
#include <algorithm>

Actor::Actor() {
	maxHealth = 100;
	health = 100;
	name = "";
}

void Actor::TakeDamage(int damage) {
	health -= damage;
}

void Actor::GiveDamage(Actor* actor,int damage) {
	actor->health -= damage;
}

void Actor::SetName(const std::string& name) {
	Actor::name = name;
}

void Actor::GiveItem(Actor* actor, Item item) {
	actor->inventory.ReceiveItem(item);

}