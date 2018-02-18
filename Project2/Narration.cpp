#include "Narration.h"

Narration::Narration(){
	//player taunts
	playerTaunt1.message = "You laugh at the Goblin and return with a hit of your own!";
	playerTaunt2.message = "you strike back";
	playerTaunt3.message = "gritting your teeth you aim for the Goblins head";
	playerTaunt4.message = "after stubbing your toe, you wince and attempt to strike";
	playerTaunt5.message = "you laugh, he laughs, the floor laughs, wait... what?";
	playerTaunt6.message = "going for a low blow, you aim for the goblins miniature testies";
	playerTaunt7.message = "You laugh and hit";
	playerTaunt8.message = "fearing your death, you strike as hard as you can";
	playerTaunt9.message = "you laugh in the face of death, and hit";
	playerTaunt10.message = "you return with a hit of your own";
	//enemy taunts
	enemyTaunt1.message = "The goblin sneers and returns with a hit of his own";
	enemyTaunt2.message = "The goblin laughs and returns with a hit";
	enemyTaunt3.message = "The goblin hits you";
	enemyTaunt4.message = "The goblin sarls and returns with a headshot";
	enemyTaunt5.message = "Laughing, the Goblin hits you back";
	enemyTaunt6.message = "hoping he doesnt miss, the Goblin hits as hard as he can";
	enemyTaunt7.message = "Trying not to miss, the Goblin hits";
	enemyTaunt8.message = "with no words, the Goblin strikes";
	enemyTaunt9.message = "preparing for a return strike, the Goblin hits";
	enemyTaunt10.message = "The goblin shouts 'I laugh in the face of danger' and strikes";
	//add player taunts to vector
	playerTaunts.push_back(playerTaunt1);
	playerTaunts.push_back(playerTaunt2);
	playerTaunts.push_back(playerTaunt3);
	playerTaunts.push_back(playerTaunt4);
	playerTaunts.push_back(playerTaunt5);
	playerTaunts.push_back(playerTaunt6);
	playerTaunts.push_back(playerTaunt7);
	playerTaunts.push_back(playerTaunt8);
	playerTaunts.push_back(playerTaunt9);
	playerTaunts.push_back(playerTaunt10);
	//add enemy taunts to vector
	enemyTaunts.push_back(enemyTaunt1);
	enemyTaunts.push_back(enemyTaunt2);
	enemyTaunts.push_back(enemyTaunt3);
	enemyTaunts.push_back(enemyTaunt4);
	enemyTaunts.push_back(enemyTaunt5);
	enemyTaunts.push_back(enemyTaunt6);
	enemyTaunts.push_back(enemyTaunt7);
	enemyTaunts.push_back(enemyTaunt8);
	enemyTaunts.push_back(enemyTaunt9);
	enemyTaunts.push_back(enemyTaunt10);

}

Speech Narration::getTaunt(char actorType, unsigned int index) {
	switch (actorType) {
	case 'e':
		if (index > enemyTaunts.size() - 1) {
			index = enemyTaunts.size() - 1;
		}
		return enemyTaunts[index];
		break;
	case 'p':
		if (index > playerTaunts.size() - 1) {
			index = playerTaunts.size() - 1;
		}
		return playerTaunts[index];
		break;
	}
}
