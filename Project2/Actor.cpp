#include "Actor.h"

Actor::Actor() {
	maxHealth = 100;
	health = 100;
}

void Actor::TakeDamage(int damage) {
	health -= damage;
}

void Actor::GiveDamage(Actor* actor,int damage) {
	actor->health -= damage;
}