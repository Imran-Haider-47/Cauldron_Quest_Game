#include <time.h> 
#include<string>
#include <stdlib.h>
#include<iostream>
using namespace std;

class Ingredients {
public:
	
	string A1_Dice[6]= { "potion", "potion", "potion", "potion", "wizard's hat", "wizard's hat" };//Action Dice 1
	string A2_Dice[6] = { "Lightning","Lightning","Lightning" ,"3","3","4" };					  //Action Dice 2
	int Magic_Dice[6] = { 1, 2, 3, 4, 5, 6 };		//Magic Dice which are 3 in number
	int Path_Blockers[6] = { 0,0,0,0,0,0 };   // Path blocker
	string Potion_Bottles [6]= { "Rotten Egg","Poison Mushroom","Horned Toad","Eye of Newt","dandelion", "bat wing" };
	string centre[3];         // To store the names of three ingredients in the centre of the board
	Ingredients()	//Default constructor
	{

	}

	int GenerateRandom()
	{
		srand(time(NULL));
		int randm = rand() % 6 + 1;
		return randm;
	}

	void Centre_Ingredients()
	{
		
		int random;
		/* generate secret number between 1 and 6 including  */

		/* initialize random seed: */
		random = GenerateRandom();
		if (random == 1)
			{
				centre[0] = Potion_Bottles[random-1];
				centre[1] = Potion_Bottles[random ];
				centre[2] = Potion_Bottles[random +1];
			}
		else if (random == 6)
			{
				centre[0] = Potion_Bottles[random-1];
				centre[1] = Potion_Bottles[random-2];
				centre[2] = Potion_Bottles[random-3];
			}
		else
			{
				centre[0] = Potion_Bottles[random];
				centre[1] = Potion_Bottles[random - 1];
				centre[2] = Potion_Bottles[random + 1];
			}

		cout << "The Indgredients in the centre are : " << endl;
		for (int i = 0; i < 3; i++)
		{
			
			cout<<i+1<<"."<< centre[i] << "  ";
			cout << endl;
		}
		cout << endl;
	}

	
	
};