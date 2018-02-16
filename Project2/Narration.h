#pragma once
#include <string>
#include <vector>
#include "Speech.h"


class Narration : public Speech{

//look narration
public:
	Narration();
	Speech lookJungle;
	Speech lookTombEntrance;
	Speech lookDepths;

//goto narration
public:
	Speech goToJungle;
	Speech goToTomb;
	Speech goToCave;
	Speech goToDepths;

//open narration
public:
	Speech openTomb;

//functions
public:
	Speech getTaunt(char, unsigned int);

//taunts
public:
	std::vector<Speech>playerTaunts;
	Speech playerTaunt1;
	Speech playerTaunt2;
	Speech playerTaunt3;
	Speech playerTaunt4;
	Speech playerTaunt5;
	Speech playerTaunt6;
	Speech playerTaunt7;
	Speech playerTaunt8;
	Speech playerTaunt9;
	Speech playerTaunt10;

	std::vector<Speech>enemyTaunts;
	Speech enemyTaunt1;
	Speech enemyTaunt2;
	Speech enemyTaunt3;
	Speech enemyTaunt4;
	Speech enemyTaunt5;
	Speech enemyTaunt6;
	Speech enemyTaunt7;
	Speech enemyTaunt8;
	Speech enemyTaunt9;
	Speech enemyTaunt10;

//scenario
public:
	Speech help;
	Speech win;
	Speech lose;
	Speech playerTrade;
	Speech allyTrade;
};

