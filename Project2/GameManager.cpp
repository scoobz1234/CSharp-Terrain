#include "GameManager.h"

namespace {
	//actors...
	Actor player("", 100, 100);
	Actor ally("", 100, 100);
	Actor enemy("Goblin", 100, 100);
	//items...
	Item potion1("Health", 1);
	Item potion2("Special 'Happy' Juice", 2);
	Item mag("Goblin's Gone Wild XXX", 1);
	Item helmet("Helmet Of Increasing Sorrow", 1);
	Item sword("Sword Of A Thousand Truths", 1);

	Narration nar;

	//enums...
	GameManager::PlayerInput pI;
	GameManager::Locations loc = GameManager::Locations::JUNGLE;
	GameManager::Locations oldLoc = GameManager::Locations::JUNGLE;
	//random generator stuff

	std::mt19937 gen(std::random_device{}());
	std::uniform_int_distribution<> rndChance(0, 5);
	std::uniform_int_distribution<> rndEChance(0, 10);
	std::uniform_int_distribution<> rndPChance(0, 20);
}

void GameManager::Battle(int situation) {
	using namespace std;
	int mDamage(0);
	Speech temp;
	switch (situation) {
	case 1:
		temp = nar.getTaunt('e', (rndEChance(gen)));
		cout << "\n" << temp.message << "\n";
		mDamage = PlayerDamageRoll<int>((rndChance(gen)));
		if (mDamage < 1) {
			std::cout << "The Goblin missed!\n";
			Battle(2);
		}
		else {
			enemy.GiveDamage(&player, (mDamage));
			cout << "The Goblin hit you for " << mDamage << " hit-points!\n";
			cout << "Your Health is now " << *player.currentHealth << endl;
			if (*player.currentHealth > 0) {
				Battle(2);
			}
			else {
				GetLineFromFile("Narrative.txt", "LOSE");
			}
		}break;
	case 2:
		temp = nar.getTaunt('p', (rndEChance(gen)));
		cout << "\n" << temp.message << "\n";
		mDamage = EnemyDamageRoll<int>((rndChance(gen)));
		if (mDamage < 1) {
			std::cout << "Your attack missed!\n";
			system("pause");
			Battle(1);
		}
		else {
			player.GiveDamage(&enemy, mDamage);
			cout << "You hit the Goblin for " << mDamage << " hit-points!\n";
			cout << "The Goblin's Health is now " << *enemy.currentHealth << endl;
			system("pause");
			if (*enemy.currentHealth > 0) {
				Battle(1);
			}
			else {
				cout << "\n" << player.mName << " has defeated the Goblin!" << endl;
				return;
			}
		}break;
	}
}

void GameManager::Looks(int chapter) {
	using namespace std;
	switch (chapter) {
	case 0: 
		GetLineFromFile("Narrative.txt", "LOOKJUNGLE"); 
		break;
	case 1:	
		GetLineFromFile("Narrative.txt", "LOOKTOMB"); 
		break;
	case 2:
		GetLineFromFile("Narrative.txt", "LOOKDEPTHS"); 
		break;
	case 3:
		GetLineFromFile("Narrative.txt", "WIN");
		break;
	case 4:	
		GetLineFromFile("Narrative.txt", "LOSE");
		break;
	default: 
		cout << "I'm looking and i don't see that...anywhere..";
	}
	return;
}

void GameManager::Open() {
	using namespace std;
	switch (loc) {
	case TOMB: 
		GetLineFromFile("Narrative.txt", "OPENTOMB"); 
		break;
	case DOOR:
		break;
	default: 
		cout << "I don't understand where that is...\n";
	}
}

void GameManager::GoTo() {
	using namespace std;
	if (loc != oldLoc) {
		switch (loc) {
		case JUNGLE: 
			GetLineFromFile("Narrative.txt", "GOTOJUNGLE"); oldLoc = loc; stage = 0;
			break;
		case TOMB: 
			GetLineFromFile("Narrative.txt", "GOTOTOMB"); oldLoc = loc; stage = 1;
			break;
		case CAVE: 
			GetLineFromFile("Narrative.txt", "GOTOCAVE"); oldLoc = loc; stage = 2;
			break;
		case DEPTHS:
			GetLineFromFile("Narrative.txt", "GOTODEPTHS"); oldLoc = loc; stage = 3;
			break;
		default: 
			cout << "I don't understand where that is..." << endl;
		}
	} 
	else { 
		cout << "I'm already there!" << endl;
	}
}

void GameManager::Setup() {
	using namespace std;
	isSetup = true;
	//items for inventory setup
	player.inventory.ReceiveItem(&helmet);
	player.inventory.ReceiveItem(&potion1);
	ally.inventory.ReceiveItem(&sword);
	ally.inventory.ReceiveItem(&mag);
	ally.inventory.ReceiveItem(&potion2);

	//player information
	string pName = "";
	cout << "Adventurer, What is your name?\n", cin >> pName;
	player.SetName(pName);
	cout << "\n Hello " << player.mName << "!\n" << "Lets begin your adventure? \n";
	Run();
}

void GameManager::Trade(Actor actor) {
	using namespace std;
	char choice;
	int iChoice(0);
	player.inventory.PrintInventory(player.mName);
	ally.inventory.PrintInventory(ally.mName);
	system("pause");

	cout << "\nWould you like to trade an item? (y or n)";
	cin >> choice;

	if (choice != 'n') {
		GetLineFromFile("Narrative.txt", "PTRADE");
		cin >> iChoice;
		ally.inventory.ReceiveItem(player.inventory.TakeItem(iChoice));
		GetLineFromFile("Narrative.txt", "ATRADE");
		cin >> iChoice;
		player.inventory.ReceiveItem(ally.inventory.TakeItem(iChoice));
		//print final inventories
		player.inventory.PrintInventory(player.mName);
		ally.inventory.PrintInventory(ally.mName);
		system("pause");
		return;
	}
	else {
		return;
	}
}

//Set Player Input To Enum
auto GameManager::PlayerInputToEnum(std::string input) {
	using namespace std;
	transform(input.begin(), input.end(), input.begin(), toupper);
	if (input == "HELLO") { 
		pI = HELLO;
		return pI;
	}
	else if (input == "INVENTORY") {
		pI = INVENTORY;	
		return pI; 
	}
	else if (input == "BATTLE") {
		pI = BATTLE; 
		return pI;
	}
	else if (input == "LOOK") {
		pI = LOOK; 
		return pI;
	}
	else if (input == "OPEN") { 
		stage += 1;
		pI = OPEN;
		return pI;
	}
	else if (input == "CLOSE") {
		pI = CLOSE;
		return pI;
	}
	else if (input == "PICKUP") {
		pI = PICKUP;
		return pI;
	}
	else if (input == "DROP") { 
		pI = HELLO;
		return pI;
	}
	else if (input == "TRADE") {
		pI = TRADE;
		return pI;
	}
	else if (input == "QUIT") {
		pI = QUIT; 
		return pI; 
	}
	else if (input == "HELP") {
		pI = HELP;
		return pI; 
	}
	else if (input == "GOTO") {
		string place;
		pI = GOTO;
		cout << "Where to?" << endl;
		cout << "--> ";
		cin >> place;
		cout << "\n";
		if (place == "tomb") { loc = TOMB; }
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

void GameManager::Run() {
	using namespace std;
	char choice = 'y';
	while (choice!= 'n') {
		string temp;
		string playerInput;
		cout << "--> ";
		cin >> playerInput;
		cout << "\n";
		PlayerInputToEnum(playerInput);
		switch (pI) {
		case HELLO:
			if (!isSetup) { 
				Setup(); 
			}
			else { 
				cout << "Hello " << player.mName << " Why don't we do something?" << endl; 
			}
			break;
		case INVENTORY:	
			player.inventory.PrintInventory(player.mName);
			break;
		case TRADE:
			Trade(ally);
			break;
		case GOTO: 
			GoTo();
			break;
		case BATTLE: 
			Battle(2);
			break;
		case OPEN: 
			Open(); 
			break;
		case LOOK: 
			Looks(stage);
			break;
		case HELP: 	
			GetLineFromFile("Narrative.txt", "HELP");
			break;
		case QUIT: choice = 'n'; 
			break;
		default: cout << "I'm sorry, i don't quite understand you..." << endl;
		}
	}
}

std::string GameManager::GetFile(std::ifstream& file) {
	using namespace std;
	string lines = "";
	if (file) {
		while (file.good()) {
			string tempLine;
			getline(file, tempLine);
			tempLine += "\n";

			lines += tempLine;
		}
		return lines;
	}
	else {
		return "ERROR File does not exist.";
	}
}

void GameManager::PrintFile(std::string title) {
	using namespace std;
	ifstream mTitle(title);
	string art = GetFile(mTitle);
	cout << art << endl;
	mTitle.close();
}

void GameManager::GetLineFromFile(std::string title, std::string searchParam) {
	using namespace std;
	ifstream file(title);
	string line="";
	for (unsigned int curLine = 0; getline(file, line,';'); curLine++) {
		if (line.find(searchParam) != string::npos) {
			cout << string(line,(searchParam.length()+1)) << endl;
		}
	}

}

void GameManager::Title() {
	using namespace std;
	PrintFile("Title.txt");
	system("PAUSE");
	cout << "\n\n\n\n";
	PrintFile("CreatedBy.txt");
	cout << "\n\n\n\n";
	system("PAUSE");
	system("cls");
	Setup();
}