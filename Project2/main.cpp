#include <stdio.h>
#include <iostream>
#include "Actor.h"
#include "Inventory.h"
#include <ctime>
#include <algorithm>

Actor player;
Actor ally;
Actor enemy;
Item potion1;
Item potion2;
Item mag;
Item helmet;
Item sword;
bool isSetup = false;
void Narrative(int);
void Trade(Actor);
void Run();
int stage = 0;

enum PlayerInput { HELLO, INVENTORY, BATTLE, LOOK, OPEN, CLOSE, PICKUP, DROP, TRADE, GOTO, QUIT, INVALID, HELP, ATTITUDE };
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

char* EnemySpeech(int choice) {
	switch (choice) {
	case 1:	return "The goblin sneers and returns with a hit of his own"; break;
	case 2:	return "The goblin laughs and returns with a hit"; break;
	case 3:	return "The goblin hits you"; break;
	case 4: return "The goblin sarls and returns with a headshot"; break;
	case 5:	return "Laughing, the Goblin hits you back"; break;
	case 6:	return "hoping he doesnt miss, the Goblin hits as hard as he can"; break;
	case 7:	return "Trying not to miss, the Goblin hits"; break;
	case 8:	return "with no words, the Goblin strikes"; break;
	case 9:	return "preparing for a return strike, the Goblin hits"; break;
	case 10:return "The goblin shouts 'I laugh in the face of danger' and strikes";	break;
	}
}

char* PlayerSpeech(int choice) {
	switch (choice) {
	case 1:	return "You laugh at the Goblin and return with a hit of your own!"; break;
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
	int choice;
	switch (situation) {
	case 1:	
		std::cout << "you chose to battle! therefor you attack first\n";
		mDamage = DamageRoll();
		if (mDamage < 1) {
			std::cout << "You missed!\n";
			system("pause");
			Battle(2);
		}else {
			player.GiveDamage(&enemy, mDamage);
			std::cout << "You hit the Goblin for " << mDamage << " hit-points!\n";
			std::cout << "The Goblin's Health is now " << *enemy.currentHealth << std::endl;
			system("pause");
			Battle(2);
		}break;
	case 2:	choice = rand() % 10 + 1;
		std::cout << "\n" << EnemySpeech(choice) << "\n";
		mDamage = DamageRoll();
		if (mDamage < 1) {
			std::cout << "The Goblin missed!\n";
			system("pause");
			Battle(3);
		}else {
			enemy.GiveDamage(&player, (mDamage));
			std::cout << "The Goblin hit you for " << mDamage << " hit-points!\n";
			std::cout << "Your Health is now " << *player.currentHealth << std::endl;
			system("pause");
			if (*player.currentHealth > 0) {
				Battle(3);
			}else {
				std::cout << "you have been defeated!\n\n" << "GAMEOVER" << std::endl;
				Narrative(5);
			}
		}break;
	case 3:	choice = rand() % 10 + 1;
		std::cout << "\n" << PlayerSpeech(choice) << "\n";
		mDamage = DamageRoll();
		if (mDamage < 1) {
			std::cout << "Your attack missed!\n";
			system("pause");
			Battle(2);
		}else {
			player.GiveDamage(&enemy, mDamage);
			std::cout << "You hit the Goblin for " << mDamage << " hit-points!\n";
			std::cout << "The Goblin's Health is now " << *enemy.currentHealth << std::endl;
			system("pause");
			if (*enemy.currentHealth > 0) {
				Battle(2);
			}else {
				std::cout << "\n" << player.name << " has defeated the Goblin!" << std::endl;
				Run();
			}
		}break;
	}
}

void Narrative(int chapter) {
	char choice;
	std::string mName = "";
	switch (chapter) {
	case 0:
		std::cout << "having a look around the jungle, you see some rather large trees, blue skies, and the ground feels soft from\n" 
			" years of leaves and compost.\n"
			"To the NORTH you see a 'Tomb' that catches your interest" << std::endl;
		Run();
		break;
	case 1:
		std::cout << "looking up at the large door, you can see a lever to the side that would most likely grant you access\n"
			"behind you is the jungle where you came from"<< std::endl;
		Run();
		break;
	case 2:
		std::cout << "You look into the 'depths' of the cave, and decide there is only one path to take, so you\n"
			"get ready to travers farther into the cave"<< std::endl;
		Run();
		break;
	case 3:
		break;
	case 7:
		std::cout << "\nCongratulations " << player.name << ", you have defeated your first enemy!\n" << std::endl;

		std::cout << "After a brief rest, " << player.name << " continued their journey forward into the tomb.\n" << player.name << " hears the pitter patter of feet upon the cobblestone once again!\n";
		std::cout << "fear setting in, and preparing for battle, " << player.name << " looks into the darkness and tries to identify his foe.\n";
		std::cout << "a Tall man named: (enter a name)\n";
		std::cin >> mName;
		ally.SetName(mName);
		std::cout << "After a long and arduous conversation, " << ally.name << " and " << player.name << " decide to join forces and traverse the tomb together!" << std::endl;
		system("pause");
		std::cout << "\nShortly after turning the next corner " << ally.name << " finds and picks up a sword." << std::endl;
		std::cout << ally.name << " motions to you that he would like to give you the item, if you would be willing to trade something." << std::endl;
		std::cout << "do you want initiate a trade? (y or n)";
		std::cin >> choice;
		if (choice != 'n') {
			Trade(ally);
		}
		else {
			std::cout << ally.name << " stabs you in the face with the sword and takes all your belongings. game over you stingy adventurer..." << std::endl;
			system("pause");
			return;
		}
		return;
		break;
	case 4:
		std::cout << "\n\n\n**********************************************************" << std::endl;
		std::cout << "**********************************************************" << std::endl;
		std::cout << "                 THANKS FOR PLAYING!!" << std::endl;
		std::cout << "**********************************************************" << std::endl;
		std::cout << "**********************************************************" << std::endl;
		system("pause");
		break;
	case 5:
		break;
	case 6:
		std::cout << "Your blood begins to fill the cracks of the cobblestone floor as the life exits your eyes.\n The goblin has his way with your lifeless body...";
		return;
		break;
	}
}
void Open() {
		switch (loc) {
		case TOMB:
			std::cout << "You pull the lever down, and the cave entrance opens, revealing a cobblestone path\n"
				"that extends as far as the eye can see...albeit the eye can't see that far into the darkness...\n"
				"shall we go inside?" << std::endl;
			Run();
			break;
		case HOLE:
			std::cout << "Nothing to open.." << std::endl;
			Run();
			break;
		case WALL:
			std::cout << "Nothing to open.." << std::endl;
			Run();
			break;
		case DOOR:
			std::cout << "You walk over to the Tomb, realizing it is MUCH larger than you originally thought.\n"
				"What am I to do now? you thought.." << std::endl;
			Run();
			break;
		case JUNGLE:
			std::cout << "Nothing to open.." << std::endl;
			Run();
			break;
		case CAVE:
			std::cout << "Nothing to open.." << std::endl;
			Run();
			break;
		case DEPTHS:
			std::cout << "Nothing to open.." << std::endl;
			Run();
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
			std::cout << "You walk back to the Jungle clearing\n"
				"now what? round and round the circle we go?" << std::endl;
			oldLoc = loc;
			stage = 0;
			Run();
			break;
		case TOMB:
			std::cout << "You walk over to the Tomb, realizing it is MUCH larger than you originally thought.\n"
				"What am I to do now? you thought.." << std::endl;
			oldLoc = loc;
			stage = 1;
			Run();
			break;
		case CAVE:
			std::cout << "As you walk inside the tomb, the door slams shut behind you. panic rushes over you, as you turn\n"
				"around and try to open the door. alas you cannot. You turn around and as your eyes adjust to the dimly\n"
				"lit cave, you think to yourself.. only one way to go now.. down..\n"
				"oh yeah.. the cave path seems to be going at a downwards incline." << std::endl;
			oldLoc = loc;
			stage = 2;
			Run();
			break;
		case DEPTHS:
			std::cout << "As you begin your decent into the dark and damp cave, you hear the quiet pitter patter of feet on the \n"
				"cobblestone floor in front of you.. a shiver runs down your spine, \n"
				"just then an ugly goblin jumps out and petitions you for battle\n" << std::endl;
			std::cout << "Shall we battle?" << std::endl;
			oldLoc = loc;
			stage = 3;
			Run();
			break;
		case HOLE:
			std::cout << "You carefully begin your decent down the hole, suddenly, you lose your grip and fall\n"
				"down what feels like an eternity, and land on a rather pillowy feeling ground.. phew.. you think \n"
				"gathering your witts, you get ready to look around" << std::endl;
			oldLoc = loc;
			stage = 4;
			Run();
			break;
		case WALL:
			std::cout << "You walk over to the Tomb, realizing it is MUCH larger than you originally thought.\n"
				"What am I to do now? you thought.." << std::endl;
			oldLoc = loc;
			stage = 1;
			Run();
			break;
		case DOOR:
			std::cout << "You walk over to the Tomb, realizing it is MUCH larger than you originally thought.\n"
				"What am I to do now? you thought.." << std::endl;
			oldLoc = loc;
			stage = 1;
			Run();
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
	potion1.name = "Health";
	potion1.numItem = 1;
	potion2.name = "Special 'Happy' Juice";
	potion2.numItem = 2;
	sword.name = "Sword Of A Thousand Truths";
	sword.numItem = 1;
	helmet.name = "Helmet Of Increasing Sorrow";
	helmet.numItem = 1;
	mag.name = "Goblin's Gone Wild XXX";
	mag.numItem = 1;
	player.inventory.ReceiveItem(helmet);
	player.inventory.ReceiveItem(potion1);
	ally.inventory.ReceiveItem(sword);
	ally.inventory.ReceiveItem(mag);
	ally.inventory.ReceiveItem(potion2);

	//player information
	std::string mName = "";
	char choice;
	std::cout << "Adventurer, What is your name?\n" << std::endl;
	std::cin >> mName;
	player.SetName(mName);
	std::cout << "\n Hello " << player.name << "!\n" << std::endl;
	std::cout << "Are you ready to begin your adventure? (y or n)\n" << std::endl;
	std::cin >> choice;
	std::cout << "\n";
	isSetup = true;
	if (choice = 'y') {
		Run();
	}
}

void Trade(Actor actor) {
	char choice;
	int iChoice;
	std::cout << "\nWould you like to check your inventory? (y or n)";
	std::cin >> choice;
	if (choice != 'n') {
		std::cout << "\n**********************************************************" << std::endl;
		std::cout << player.name << "'s Inventory:" << std::endl;
		player.inventory.PrintInventory();
		std::cout << "**********************************************************" << std::endl;
		system("pause");
		std::cout << "\nWould you like to check your allies inventory? (y or n)";
		std::cin >> choice;
		if (choice != 'n') {
			std::cout << "\n**********************************************************" << std::endl;
			std::cout << ally.name << "'s Inventory:" << std::endl;
			ally.inventory.PrintInventory();
			std::cout << "**********************************************************" << std::endl;
			system("pause");
		}
		else {
		//do nothing
		}
		std::cout << "\nwould you like to trade an item? (y or n)";
		std::cin >> choice;
		if (choice != 'n') {
			std::cout << "\n**********************************************************" << std::endl;
			std::cout << player.name << "'s Inventory:" << std::endl;
			player.inventory.PrintInventory();
			std::cout << "**********************************************************" << std::endl;
			std::cout << "Which item would you like to trade?\n";
			std::cin >> iChoice;
			switch (iChoice) {
			default:
				ally.inventory.ReceiveItem(player.inventory.TakeItem(iChoice));
				player.inventory.RemoveItem(iChoice);
				std::cout << "Which item would you like to take from your ally?" << std::endl;
				std::cin >> iChoice;
				player.inventory.ReceiveItem(ally.inventory.TakeItem(iChoice));
				ally.inventory.RemoveItem(iChoice);
				system("pause");
				//print final inventories
				std::cout << "\n**********************************************************" << std::endl;
				std::cout << player.name << "'s Inventory:" << std::endl;
				player.inventory.PrintInventory();
				std::cout << "**********************************************************" << std::endl;
				std::cout << "\n\n**********************************************************" << std::endl;
				std::cout << ally.name << "'s Inventory:" << std::endl;
				ally.inventory.PrintInventory();
				std::cout << "**********************************************************" << std::endl;
				system("pause");
				Narrative(3);
				break;
			}

		}
	}
}



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
		if (place == "tomb") {
			loc = TOMB;
		}
		else if (place == "wall") {
			loc = WALL;
		}
		else if (place == "door") {
			loc = DOOR;
		}
		else if (place == "hole") { 
			loc = HOLE; 
		}
		else if (place == "jungle") {
			loc = JUNGLE;
		}
		else if (place == "cave") {
			loc = CAVE;
		}
		else if (place == "depths") {
			loc = DEPTHS;
		}
		else {
			loc = NOWHERE;
		}
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
		case HELLO: (!isSetup) ? Setup() : (std::cout << Communication(1) << std::endl);
			continue;
		case INVENTORY:
			continue;
		case TRADE:
			continue;
		case GOTO:
			GoTo();
			continue;
		case BATTLE:
			Battle(1);
			continue;
		case PICKUP:
			continue;
		case DROP:
			continue;
		case OPEN:
			Open();
			continue;
		case CLOSE:
			continue;
		case LOOK:
			Narrative(stage);
			continue;
		case QUIT:
			std::cout << "If your sure you want to quit, type quit again " << std::endl;
			choice = 'n';
			break;
		case HELP:
			std::cout << "*************************************" << std::endl;
			std::cout << "               COMMANDS              " << std::endl;
			std::cout << "*************************************" << std::endl;
			std::cout << "Hello, Inventory, Battle, Look, Open " << std::endl;
			std::cout << "Pickup, Drop, Trade, Goto, Quit, Help" << std::endl;
			std::cout << "*************************************" << std::endl;
			std::cout << "               COMMANDS              " << std::endl;
			std::cout << "*************************************" << std::endl;
			continue;
		case ATTITUDE:
			std::cout << "That attitude will get you nowhere " << player.name << std::endl;
			continue;
		default:
			std::cout << "I'm sorry, i don't quite understand you..." << std::endl;
			continue;
		}
		break;
	} while (choice != 'n');
	
}


int main() {
	std::cout << "Start with 'hello'" << std::endl;
	srand(time(0));
	Run();
	return 0;
}
