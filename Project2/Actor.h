#pragma once
class Actor
{
private:
	int maxHealth;
	int health;
public:
	Actor();
	void TakeDamage(int);
	void GiveDamage(Actor*,int);
	void heal(int);
};

