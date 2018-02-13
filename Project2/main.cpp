#include <stdio.h>
#include <iostream>
#include "Actor.h"
#include "Inventory.h"
#include <ctime>

Actor player;
Actor ally;
Actor enemy;
Item potion1;
Item potion2;
Item mag;
Item helmet;
Item sword;
void Narrative(int);
void Trade(Actor);

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
	case 1:
		return "The goblin sneers and returns with a hit of his own";
		break;
	case 2:
		return "The goblin laughs and returns with a hit";
		break;
	case 3:
		return "The goblin hits you";
		break;
	case 4:
		return "The goblin sarls and returns with a headshot";
		break;
	case 5:
		return "Laughing, the Goblin hits you back";
		break;
	case 6:
		return "hoping he doesnt miss, the Goblin hits as hard as he can";
		break;
	case 7:
		return "Trying not to miss, the Goblin hits";
		break;
	case 8:
		return "with no words, the Goblin strikes";
		break;
	case 9:
		return "preparing for a return strike, the Goblin hits";
		break;
	case 10:
		return "The goblin shouts 'I laugh in the face of danger' and strikes";
		break;
	}
}

char* PlayerSpeech(int choice) {
	switch (choice) {
	case 1:
		return "You laugh at the Goblin and return with a hit of your own!";
		break;
	case 2:
		return "you strike back";		
		break;
	case 3:
		return "gritting your teeth you aim for the Goblins head";		
		break;
	case 4:
		return "after stubbing your toe, you wince and attempt to strike";		
		break;
	case 5:
		return "you laugh, he laughs, the floor laughs, wait... what?";		
		break;
	case 6:
		return "going for a low blow, you aim for the goblins miniature testies";		
		break;
	case 7:
		return "You laugh and hit";		
		break;
	case 8:
		return "fearing your death, you strike as hard as you can";		
		break;
	case 9:
		return "you laugh in the face of death, and hit";		
		break;
	case 10:
		return "you return with a hit of your own";		
		break;
	}
}

void Battle(int situation) {
	int mDamage = 0;
	int choice;
	switch (situation) {
	case 1:
		std::cout << "you chose to battle! therefor you attack first\n";
		mDamage = DamageRoll();
		if (mDamage < 1) {
			std::cout << "You missed!\n";
			system("pause");
			Battle(3);
		}
		else {
			player.GiveDamage(&enemy, mDamage);
			std::cout << "You hit the Goblin for " << mDamage << " hit-points!\n";
			std::cout << "The Goblin's Health is now " << *enemy.currentHealth << std::endl;
			system("pause");
			Battle(3);
		}
		break;
	case 2:
		std::cout << "you chose to run! However, the Goblin traps you in place and you're forced to fight! The goblin hits first!\n";
		mDamage = DamageRoll();
		if (mDamage < 1) {
			std::cout << "The Goblin missed!\n";
			system("pause");
			Battle(4);
		}
		else {
			enemy.GiveDamage(&player, mDamage);
			std::cout << "The Goblin hit you for " << mDamage << " hit-points!\n";
			std::cout << "Your Health is now " << *player.currentHealth << std::endl;
			system("pause");
			Battle(4);
		}
		break;
	case 3:
		choice = rand() % 10 + 1;
		std::cout << "\n" << EnemySpeech(choice) << "\n";
		mDamage = DamageRoll();
		if (mDamage < 1) {
			std::cout << "The Goblin missed!\n";
			system("pause");
			Battle(4);
		}
		else {
			enemy.GiveDamage(&player, (mDamage));
			std::cout << "The Goblin hit you for " << mDamage << " hit-points!\n";
			std::cout << "Your Health is now " << *player.currentHealth << std::endl;
			system("pause");
			if (*player.currentHealth > 0) {
				Battle(4);
			}
			else {
				std::cout << "you have been defeated!\n\n" << "GAMEOVER" << std::endl;
				Narrative(5);
			}
		}
		break;
	case 4:
		choice = rand() % 10 + 1;
		std::cout << "\n" << PlayerSpeech(choice) << "\n";
		mDamage = DamageRoll();
		if (mDamage < 1) {
			std::cout << "Your attack missed!\n";
			system("pause");
			Battle(3);
		}
		else {
			player.GiveDamage(&enemy, mDamage);
			std::cout << "You hit the Goblin for " << mDamage << " hit-points!\n";
			std::cout << "The Goblin's Health is now " << *enemy.currentHealth << std::endl;
			system("pause");
			if (*enemy.currentHealth > 0) {
				Battle(3);
			}
			else {
				std::cout << "\n" << player.name << " has defeated the Goblin!" << std::endl;
				Narrative(2);
			}
		}
		break;
	}
}

void Narrative(int chapter) {
	char choice;
	int bChoice;
	std::string mName = "";
	switch (chapter) {
	case 1:
		std::cout << "**********************************************************" << std::endl;
		std::cout << "**********************************************************" << std::endl;
		std::cout << "While walking through the jungle, you stumble upon an old tomb. Although it looks like it could be dangerous"
			" your sense of adventure overides any thoughts of turning back...\n" << "do you open the tomb? (y or n)" << std::endl;
		std::cin >> choice;
		if (choice != 'n') {
			std::cout << "\n**********************************************************" << std::endl;
			std::cout << "**********************************************************" << std::endl;
			std::cout << "As you enter the dark and damp cave, you hear the quiet pitter patter of feet on the cobblestone floor in front of you.. a shiver runs down your spine, just then an ugly goblin jumps out and petitions you for battle\n";
			std::cout << "What do you choose to do:\n (1)Battle\n (2)Run\n";
			std::cin >> bChoice;
			if (bChoice != 2) {
				Battle(1);
			}
			else {
				Battle(2);
			}
		}
		break;
	case 2:
		std::cout << "\n**********************************************************" << std::endl;
		std::cout << "**********************************************************" << std::endl;
		std::cout << "\nCongratulations " << player.name << ", you have defeated your first enemy!\n" << std::endl;
		std::cout << "**********************************************************" << std::endl;
		std::cout << "**********************************************************" << std::endl;
		std::cout << "After a brief rest, " << player.name << " continued their journey forward into the tomb.\n" << player.name << " hears the pitter patter of feet upon the cobblestone once again!\n";
		std::cout << "fear setting in, and preparing for battle, " << player.name << " looks into the darkness and tries to identify his foe.\n";
		std::cout << "**********************************************************" << std::endl;
		std::cout << "**********************************************************" << std::endl;
		std::cout << "a Tall man named: (enter a name)\n";
		std::cin >> mName;
		ally.SetName(mName);
		std::cout << "After a long and arduous conversation, " << ally.name << " and " << player.name << " decide to join forces and traverse the tomb together!" << std::endl;
		system("pause");
		std::cout << "**********************************************************" << std::endl;
		std::cout << "**********************************************************" << std::endl;
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
	case 3:
		std::cout << "\n\n\n**********************************************************" << std::endl;
		std::cout << "**********************************************************" << std::endl;
		std::cout << "                 THANKS FOR PLAYING!!" << std::endl;
		std::cout << "**********************************************************" << std::endl;
		std::cout << "**********************************************************" << std::endl;
		system("pause");
		break;
	case 4:
		break;
	case 5:
		std::cout << "Your blood begins to fill the cracks of the cobblestone floor as the life exits your eyes.\n The goblin has his way with your lifeless body...";
		return;
		break;
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
	switch (choice) {
	case 'y':
		Narrative(1);
		break;
	case 'Y':
		Narrative(1);
		break;
	default:
		return;
		break;
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


int main() {
	srand(time(0));
	Setup();
	system("PAUSE");
	return 0;

}
