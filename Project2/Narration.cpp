#include "Narration.h"



Narration::Narration(){
	//message when looking in the jungle
	lookJungle.name = "jungle";
	lookJungle.message = "having a look around the jungle, you see some rather large trees, blue skies, \n" 
		"and the ground feels soft from years of leaves and compost.\n"
		"To the NORTH you see a 'Tomb' that catches your interest";
	//message when looking at the tomb door
	lookTombEntrance.name = "tomb";
	lookTombEntrance.message = "looking up at the large door, you can see a lever to the side that \n"
		"would most likely grant you access behind you is the jungle where you came from";
	//message when looking in the depths
	lookDepths.name = "depths";
	lookDepths.message = "You look into the 'depths' of the cave, and decide there is only one path to take,\n" 
		"so you get ready to travers farther into the cave";
	//message when opening the tomb
	openTomb.name = "oTomb";
	openTomb.message = "You pull the lever down, and the cave entrance opens, revealing a cobblestone path\n"
		"that extends as far as the eye can see...albeit the eye can't see that far into the darkness...\n"
		"shall we go inside?";
	//message when entering the cave
	goToCave.name = "";
	goToCave.message = "As you walk inside the tomb, the door slams shut behind you. panic rushes over you,\n" 
		"as you turn around and try to open the door. alas you cannot. \n"
		"You turn around and as your eyes adjust to the dimly\n"
		"lit cave, you think to yourself.. only one way to go now.. down..\n"
		"oh yeah.. the cave path seems to be going at a downwards incline.";
	//message when going to jungle from tomb entrance
	goToJungle.name = "toJungle";
	goToJungle.message = "You walk back to the Jungle clearing\n"
		"now what? round and round the circle we go?";
	//message when going to depths from cave
	goToDepths.name = "toDepths";
	goToDepths.message = "As you begin your decent into the dark and damp cave, \n"
		"you hear the quiet pitter patter of feet"" on the cobblestone floor in front of you..\n"
		" a shiver runs down your spine, just then an ugly goblin jumps out and petitions you for battle\n" 
		"Shall we battle?";
	//message when going to tomb from jungle
	goToTomb.name = "toTomb";
	goToTomb.message = "You walk over to the Tomb, realizing it is MUCH larger than you originally thought.\n"
		"What am I to do now? you thought..";
	//player taunts
	playerTaunt1.name = "pTaunt1";
	playerTaunt1.message = "You laugh at the Goblin and return with a hit of your own!";
	playerTaunt2.name = "pTaunt2";
	playerTaunt2.message = "you strike back";
	playerTaunt3.name = "pTaunt2";
	playerTaunt3.message = "gritting your teeth you aim for the Goblins head";
	playerTaunt4.name = "pTaunt2";
	playerTaunt4.message = "after stubbing your toe, you wince and attempt to strike";
	playerTaunt5.name = "pTaunt2";
	playerTaunt5.message = "you laugh, he laughs, the floor laughs, wait... what?";
	playerTaunt6.name = "pTaunt2";
	playerTaunt6.message = "going for a low blow, you aim for the goblins miniature testies";
	playerTaunt7.name = "pTaunt2";
	playerTaunt7.message = "You laugh and hit";
	playerTaunt8.name = "pTaunt2";
	playerTaunt8.message = "fearing your death, you strike as hard as you can";
	playerTaunt9.name = "pTaunt2";
	playerTaunt9.message = "you laugh in the face of death, and hit";
	playerTaunt10.name = "pTaunt2";
	playerTaunt10.message = "you return with a hit of your own";
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
	//enemy taunts
	enemyTaunt1.name = "eTaunt1";
	enemyTaunt1.message = "The goblin sneers and returns with a hit of his own";
	enemyTaunt2.name = "eTaunt2";
	enemyTaunt2.message = "The goblin laughs and returns with a hit";
	enemyTaunt3.name = "eTaunt2";
	enemyTaunt3.message = "The goblin hits you";
	enemyTaunt4.name = "eTaunt2";
	enemyTaunt4.message = "The goblin sarls and returns with a headshot";
	enemyTaunt5.name = "eTaunt2";
	enemyTaunt5.message = "Laughing, the Goblin hits you back";
	enemyTaunt6.name = "eTaunt2";
	enemyTaunt6.message = "hoping he doesnt miss, the Goblin hits as hard as he can";
	enemyTaunt7.name = "eTaunt2";
	enemyTaunt7.message = "Trying not to miss, the Goblin hits";
	enemyTaunt8.name = "eTaunt2";
	enemyTaunt8.message = "with no words, the Goblin strikes";
	enemyTaunt9.name = "eTaunt2";
	enemyTaunt9.message = "preparing for a return strike, the Goblin hits";
	enemyTaunt10.name = "eTaunt2";
	enemyTaunt10.message = "The goblin shouts 'I laugh in the face of danger' and strikes";
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
	//help message
	help.name = "help";
	help.message = 
	"*************************************\n"
	"               COMMANDS              "
	"*************************************"
	"Hello, Inventory, Battle, Look, Open "
	"Pickup, Drop, Trade, Goto, Quit, Help"
	"*************************************"
	"               COMMANDS              "
	"*************************************";
	//win situation
	win.name = "win";
	win.message = "\n\n\n"
	"**********************************************************\n"
	"**********************************************************\n"
	"                 THANKS FOR PLAYING!!\n"
	"**********************************************************\n"
	"**********************************************************\n"; 
	//lose situation
	lose.name = "lose";
	lose.message = "Your blood begins to fill the cracks of the cobblestone floor\n"
		"as the life exits your eyes.\n "
		"The goblin has his way with your lifeless body...";

	playerTrade.name = "pTrade";
	playerTrade.message = "Select the index of the item you would like to trade?\n";
	playerTrade.name = "aTrade";
	playerTrade.message = "Select the index of the item you would from your ally?\n";

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
