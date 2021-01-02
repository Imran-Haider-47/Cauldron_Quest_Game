#include<iostream>
#include "Game.cpp"

using namespace std;
class Player 
{
public:
	
	string Players_name; // An array of names of players 
	int Players_age;     // An array of age of players which we will use for the turns of players. 
							//Minimum 2 and maximum 4 players are allowed to play game. 
	Player()
	{
		
	}
	void Set_Player_Name(string name)
	{
		Players_name = name;
	}
	void Set_Player_Age(int age)
	{
		Players_age = age;
	}
	string Get_Player_Name()
	{
		return Players_name;
	}
	int Get_Player_Age()
	{
		return Players_age;
	}
	
};