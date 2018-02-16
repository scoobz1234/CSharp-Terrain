#include <stdio.h>
#include <iostream>
#include "Actor.h"
#include "Inventory.h"
#include <ctime>
#include <algorithm>
#include "Narration.h"

Actor player("",100,100);
Actor ally("",100,100);
Actor enemy("Goblin",100,100);
Item potion1("Health", 1);
Item potion2("Special 'Happy' Juice", 2);
Item mag("Goblin's Gone Wild XXX", 1);
Item helmet("Helmet Of Increasing Sorrow", 1);
Item sword("Sword Of A Thousand Truths", 1);
Narration nar;
bool isSetup = false;
void Narrative(int);
void Trade(Actor);
void Run();
int stage = 0;

enum PlayerInput { HELLO, INVENTORY, BATTLE, LOOK, OPEN, CLOSE, PICKUP, 
	DROP, TRADE, GOTO, QUIT, INVALID, HELP, ATTITUDE };
PlayerInput pI;

enum Locations { TOMB, HOLE, DOOR, WALL, CAVE, DEPTHS, JUNGLE, NOWHERE };
Locations loc = JUNGLE;
Locations oldLoc = JUNGLE;

int DamageRoll() {
	int chance = rand() % 5;
	if (chance != 0) {
		return rand() % 20;
	}
	else {
		return 0;
	}
}

char* Communication(int choice) {
	switch (choice) {
	case 1:	return "Hi, we going to have a look around?"; break;
	case 2:	return "you strike back"; break;
	case 3:	return "gritting your teeth you aim for the Goblins head"; break;
	case 4:	return "after stubbing your toe, you wince and attempt to strike"; break;
	case 5:	return "you laugh, he laughs, the floor laughs, wait... what?"; break;
	case 6:	return "going for a low blow, you aim for the goblins miniature testies"; break;
	case 7:	return "You laugh and hit"; break;
	case 8:	return "fearing your death, you strike as hard as you can"; break;
	case 9:	return "you laugh in the face of death, and hit"; break;
	case 10: return "you return with a hit of your own"; break;
	}
}

void Battle(int situation) {
	int mDamage(0);
	Speech temp;
	switch (situation) {
	case 1:
		temp = nar.getTaunt('e', (rand() % 10));
		std::cout << "\n" << temp.message << "\n";
		mDamage = DamageRoll();
		if (mDamage < 1) {
			std::cout << "The Goblin missed!\n";
			system("pause");
			Battle(2);
		}else {
			enemy.GiveDamage(&player, (mDamage));
			std::cout << "The Goblin hit you for " << mDamage << " hit-points!\n";
			std::cout << "Your Health is now " << *player.currentHealth << std::endl;
			system("pause");
			if (*player.currentHealth > 0) {
				Battle(2);
			}else {
				std::cout << "you have been defeated!\n\n" << "GAMEOVER" << std::endl;
				Narrative(5);
			}
		}break;
	case 2:	
		temp = nar.getTaunt('p', (rand() % 10));
		std::cout << "\n" << temp.message << "\n";
		mDamage = DamageRoll();
		if (mDamage < 1) {
			std::cout << "Your attack missed!\n";
			system("pause");
			Battle(1);
		}else {
			player.GiveDamage(&enemy, mDamage);
			std::cout << "You hit the Goblin for " << mDamage << " hit-points!\n";
			std::cout << "The Goblin's Health is now " << *enemy.currentHealth << std::endl;
			system("pause");
			if (*enemy.currentHealth > 0) {
				Battle(1);
			}else {
				std::cout << "\n" << player.mName << " has defeated the Goblin!" << std::endl;
				return;
			}
		}break;
	}
}

void Narrative(int chapter) {
	char choice;
	std::string lName = "";
	std::string temp = "";
	switch (chapter) {
	case 0: std::cout << nar.lookJungle.message << std::endl; break;
	case 1:	std::cout << nar.lookTombEntrance.message << std::endl; break;
	case 2: std::cout << nar.lookDepths.message << std::endl; break;
	case 3:	break;
	case 7:
		std::cout << "\nCongratulations " << player.mName << ", you have defeated your first enemy!\n" << std::endl;

		std::cout << "After a brief rest, " << player.mName << " continued their journey forward into the tomb.\n" << player.mName << " hears the pitter patter of feet upon the cobblestone once again!\n";
		std::cout << "fear setting in, and preparing for battle, " << player.mName << " looks into the darkness and tries to identify his foe.\n";
		std::cout << "a Tall man named: (enter a name)\n";
		std::cin >> lName;
		ally.SetName(lName);
		std::cout << "After a long and arduous conversation, " << ally.mName << " and " << player.mName << " decide to join forces and traverse the tomb together!" << std::endl;
		system("pause");
		std::cout << "\nShortly after turning the next corner " << ally.mName << " finds and picks up a sword." << std::endl;
		std::cout << ally.mName << " motions to you that he would like to give you the item, if you would be willing to trade something." << std::endl;
		std::cout << "do you want initiate a trade? (y or n)";
		std::cin >> choice;
		if (choice != 'n') {
			Trade(ally);
		}
		else {
			std::cout << ally.mName << " stabs you in the face with the sword and takes all your belongings. game over you stingy adventurer..." << std::endl;
			system("pause");
			return;
		}
		return;
		break;
	case 4:	std::cout << nar.win.message << std::endl; break;
	case 5:	break;
	case 6:	std::cout << nar.win.message << std::endl; return; break;
	}
	return;
}
void Open() {
		switch (loc) {
		case TOMB:
			std::cout << nar.openTomb.message << std::endl;
			return;
			break;
		case DOOR:
			return;
			break;
		default:
			std::cout << "I don't understand where that is..." << std::endl;
			break;

		}
}

void GoTo() {
	if (loc != oldLoc) {
		switch (loc) {
		case JUNGLE:
			std::cout << nar.goToJungle.message << std::endl;
			oldLoc = loc;
			stage = 0;
			return;
			break;
		case TOMB:
			std::cout << nar.goToTomb.message << std::endl;
			oldLoc = loc;
			stage = 1;
			return;
			break;
		case CAVE:
			std::cout << nar.goToCave.message << std::endl;
			oldLoc = loc;
			stage = 2;
			return;
			break;
		case DEPTHS:
			std::cout << nar.goToDepths.message << std::endl;
			oldLoc = loc;
			stage = 3;
			return;
			break;
		case WALL:
			//TODO
			std::cout << nar.goToJungle.message << std::endl;
			oldLoc = loc;
			stage = 3;
			return;
			break;
		case DOOR:
			//TODO
			std::cout << nar.goToJungle.message << std::endl;
			oldLoc = loc;
			stage = 3;
			return;
			break;
		default:
			std::cout << "I don't understand where that is..." << std::endl;
			break;
		}
	}
	else {
		std::cout << "I'm already there!" << std::endl;
	}
}

void Setup() {
	//items for inventory setup
	player.inventory.ReceiveItem(&helmet);
	player.inventory.ReceiveItem(&potion1);
	ally.inventory.ReceiveItem(&sword);
	ally.inventory.ReceiveItem(&mag);
	ally.inventory.ReceiveItem(&potion2);

	//player information
	std::string lName = "";
	std::cout << "Adventurer, What is your name?\n", std::cin >> lName;
	player.SetName(lName);
	std::cout << "\n Hello " << player.mName << "!\n" << "Lets begin your adventure? \n";
	return;
}

void Trade(Actor actor) {
	char choice;
	int iChoice;
		player.inventory.PrintInventory();
		ally.inventory.PrintInventory();
		system("pause");

		std::cout << "\nWould you like to trade an item? (y or n)";
		std::cin >> choice;

		if (choice != 'n') {
			std::cout << nar.playerTrade.message;
			std::cin >> iChoice;
			ally.inventory.ReceiveItem(player.inventory.TakeItem(iChoice));
			std::cout << nar.allyTrade.message;
			std::cin >> iChoice;
			player.inventory.ReceiveItem(ally.inventory.TakeItem(iChoice));
			//print final inventories
			player.inventory.PrintInventory();
			ally.inventory.PrintInventory();
			system("pause");
			return;
		}
		else {
			return;
		}
	}

//Set Player Input To Enum
auto pI2E(std::string input){
	std::transform(input.begin(), input.end(),input.begin(), toupper);
	if (input == "HELLO") {	pI = HELLO;	return pI; }
	if (input == "INVENTORY") {	pI = INVENTORY;	return pI; }
	if (input == "BATTLE") { pI = BATTLE; return pI; }
	if (input == "LOOK") { pI = LOOK; return pI; }
	if (input == "OPEN") { stage += 1; pI = OPEN; return pI; }
	if (input == "CLOSE") { pI = CLOSE; return pI; }
	if (input == "PICKUP") { pI = PICKUP; return pI; }
	if (input == "DROP") { pI = HELLO; return pI; }
	if (input == "TRADE") { pI = TRADE; return pI; }
	if (input == "QUIT") { pI = QUIT; return pI; }
	if (input == "HELP") { pI = HELP; return pI; }
	if (input == "GOTO") { 
		std::string place;
		pI = GOTO; 
		std::cout << "Where to?" << std::endl;
		std::cout << "--> ";
		std::cin >> place;
		std::cout << "\n";
		if (place == "tomb") { loc = TOMB; }
		else if (place == "wall") {	loc = WALL;	}
		else if (place == "door") {	loc = DOOR;	}
		else if (place == "hole") { loc = HOLE;	}
		else if (place == "jungle") { loc = JUNGLE; }
		else if (place == "cave") {	loc = CAVE; }
		else if (place == "depths") { loc = DEPTHS; }
		else { loc = NOWHERE; }
		return pI; 
	}
	pI = INVALID;
	return pI;
}

void Run() {
	char choice = 'y';
	do {
		std::string playerInput;
		std::cout << "--> ";
		std::cin >> playerInput;
		std::cout << "\n";
		pI2E(playerInput);
		switch (pI) {
		case HELLO:
			if (!isSetup) {	Setup(); }
			else { std::cout << "Hello " << player.mName << " Why don't we do something?" << std::endl; }
			break;
		case INVENTORY:	break;
		case TRADE:	Trade(ally); break;
		case GOTO: GoTo(); break;
		case BATTLE: Battle(1); break;
		case PICKUP: break;
		case DROP: break;
		case OPEN: Open(); break;
		case CLOSE: break;
		case LOOK: Narrative(stage); break;
		case HELP: nar.help.message;
			break;
		case ATTITUDE: std::cout << "That attitude will get you nowhere " << player.mName << std::endl; break;
		case QUIT: choice = 'n'; break;
		default: std::cout << "I'm sorry, i don't quite understand you..." << std::endl; break;
		}
	} while (choice != 'n');
}


int main() {
	srand(time(0));
	std::cout << "Don't be rude.. say: 'hello'" << std::endl;
	Run();
	return 0;
}
