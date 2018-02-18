#pragma once
#include "Actor.h"
#include "Inventory.h"
#include "templates.h"
#include "Narration.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <random>
#include <Windows.h>
#include <sstream>

class GameManager{
public:
	enum PlayerInput {
		HELLO, 
		INVENTORY, 
		BATTLE, 
		LOOK, 
		OPEN, 
		CLOSE,
		PICKUP,
		DROP, 
		TRADE, 
		GOTO, 
		QUIT, 
		INVALID,
		HELP
	};
	enum Locations { 
		TOMB, 
		HOLE, 
		DOOR, 
		WALL,
		CAVE,
		DEPTHS,
		JUNGLE,
		NOWHERE 
	};

public:
	void Battle(int);
	void Looks(int);
	void Open();
	void GoTo();
	void Setup();
	void Trade(Actor);
	void Title();
	auto PlayerInputToEnum(std::string);
	std::string GetFile(std::ifstream&);
	void PrintFile(std::string title);
	void GetLineFromFile(std::string,std::string);
	void Run();

private:
	bool isSetup{ false };
	int stage{ 0 };
};

