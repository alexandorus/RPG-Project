#include<iostream>
#include<string>
#include<time.h>
using namespace std;

class MMO
{
private:

	string player_name;
	string player_class;

public:
	double MobRounds(int rounds, int Player_diffuculity)
	{
		if (rounds < Player_diffuculity)
		{
			cout << "Round " << rounds << endl;
			rounds++;
			char choice;
			cout << " do you want to attack (a) or block (b)" << endl;
			cin >> choice;
			if (choice == 'a')
			{
				if (rand() % 101 < PlayerWarrior.Crit_damage_modifier) // crit chance
				{
					PlayerWarrior.basic_attack = PlayerWarrior.basic_attack + (PlayerWarrior.basic_attack * (PlayerWarrior.Crit_damage_modifier / 100));
					MobMinion.base_hp = MobMinion.base_hp - PlayerWarrior.basic_attack;//n
					cout << "NICE! you did critical damage for " << PlayerWarrior.basic_attack * PlayerWarrior.Crit_damage_modifier / 100 << " to the minion!" << endl;
					cout << "the minion attacks back for " << MobMinion.attack << endl;
					PlayerWarrior.base_Hp = PlayerWarrior.base_Hp - MobMinion.attack;//t
					cout << "your health is now " << PlayerWarrior.base_Hp << endl;
					cout << "the minion health is " << MobMinion.base_hp << endl;


				}
				else
				{
					MobMinion.base_hp = MobMinion.base_hp - PlayerWarrior.basic_attack;	//n
					cout << "the minion attacks back for " << MobMinion.attack << endl;
					PlayerWarrior.base_Hp = PlayerWarrior.base_Hp - MobMinion.attack;//t
					cout << "your health is now " << PlayerWarrior.base_Hp << endl;
					cout << "the minion health is " << MobMinion.base_hp << endl;
				}
			}
			else
			{

				cout << "you block the minion's attack!" << endl;
				cout << "your health is now " << PlayerWarrior.base_Hp << endl;

			}


			MobRounds(rounds, Player_diffuculity);
		}
		else

			return PlayerWarrior.base_Hp;
	}


	struct Player_class
	{
		// character stats based on random

		double basic_attack = (rand() % 51);
		double base_Hp = 500;
		double block = (rand() % 101);
		double Crit_damage_modifier = (rand() % 101);

	};
	Player_class PlayerWarrior;

	void SetPlayer_name(string x)		// function to store the string name from private memeber
	{
		player_name = x;
	}

	string GetPlayer_name()				//output string name in member
	{
		return player_name;
	}
	void SetPlayer_class(string c)		//function to save player class
	{
		player_class = c;
	}

	string GetPlayer_class()			// function to output class name
	{
		return player_class;
	}


	struct Minion
	{
		double base_hp = 1000;
		double attack = 75;

	};
	Minion MobMinion;

};


int main()
{
	srand(time(NULL));

	MMO character;		// class object
	string userName;	//userinput name
	string userclass;	// userinput class
	int UserMode;
	int Inital_round = 1;
	cout << "What is your name? " << endl;
	cin >> userName;
	character.SetPlayer_name(userName); // assign private member name from userinput
	cout << endl;
	cout << "Hello " << character.GetPlayer_name() << " we need your assistance. Please tell me what class are you?" << endl;
	cout << endl;
	cout << "1) Warrior" << endl;
	cout << "2) Archer" << endl;
	cout << "3) Mage" << endl;
	cout << endl;
	cout << "Please enter your class " << endl;
	cin >> userclass;
	character.SetPlayer_class(userclass);
	cout << endl;
	cout << character.GetPlayer_name() << " these are your character stats " << endl;
	cout << "Health Points : " << character.PlayerWarrior.base_Hp << endl;
	cout << "Attack : " << character.PlayerWarrior.basic_attack << endl;
	cout << "Block Proficiency :" << character.PlayerWarrior.block << endl;
	cout << "Critical Chance :" << character.PlayerWarrior.Crit_damage_modifier << endl;
	cout << endl;
	cout << "The goal of this game is to surive until the end of the round " << endl;
	cout << endl;
	cout << "Which difficulty would you like to challange? Please enter number corresponding with the mode " << endl;
	cout << "1) Noivce" << endl;
	cout << "2) intermediate" << endl;
	cout << "3) Expert " << endl;
	cin >> UserMode;
	if (UserMode != 1 || UserMode != 2 || UserMode != 3)
	{
		cout << "Error please type the number" << endl;
		cin >> UserMode;
	}
	if (UserMode == 1)
	{
		UserMode = 5;

		cout << "The new base attack is " << character.PlayerWarrior.basic_attack * 3 << endl;
	}
	else if (UserMode == 2)
	{
		UserMode = 7;

		cout << "The new base attack is " << character.PlayerWarrior.basic_attack * 2 << endl;
	}
	else if (UserMode == 3)
	{
		UserMode = 10;
		cout << "The new base attack is " << character.PlayerWarrior.basic_attack *1.5 << endl;
	}
	else
	{
		cout << "Invalid Entry " << endl;
		cout << "Please enter number again ";
		cin >> UserMode;
	}
	cout << "Please help us find our lost relic inside this dungeon!" << endl;

	cout << "you encounter your first enemy, the battle start!" << endl;
	double ReturnPlayerHealth = character.MobRounds(Inital_round, UserMode);

	if (ReturnPlayerHealth != 0)
	{
		
		cout << "you won! " << endl;
		

	}
	else
	{
		cout << "why" << endl;

	}

	system("pause");
}