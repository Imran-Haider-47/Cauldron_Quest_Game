#include<iostream>
#include "Player.cpp"

using namespace std;



int main()
{

	int p;
	cout << "***************** Main  Menu **********************" << endl;
	cout << "* Enter the number of players (Note: Minimum 2 and maximum 4 are allowed to play game" << endl;
	cin >> p;
	while (p < 2 || p>4) 
	{
		cout << "Invalid input. Enter the no. of players again" << endl;
		cin >> p;
	}
	string name;
	int age;
	Game *game = new Game;
	Player *player=new Player[4];

	for (int i = 0; i < p; i++)
	{
		cout << "Enter the name of Player# " << i+1<<"  : ";
		cin >> name;
		cout << "Enter the age of player (Note: Age group is 6+) :  ";
		cin >> age;
		while (age< 6)
		{
			cout << "Warning!!! You are kid. You cannot play this game ." << endl;
			cout<<"Enter the name of Player# " << i+1;
			cin >> name;
			cout << "Enter the age of Player # " << i+1;
			cin >> age;
		}
		player[i].Set_Player_Name(name);
		player[i].Set_Player_Age(age);

	}
	
	// Sorting the players by the age in an ascending order for their turn according to age. 
							//so that youngest can go first ;
	for (int j = 0; j < p; j++)
	{
		for(int i=0;i<p-j-1;i++)
		if (player[i].Get_Player_Age() > player[i + 1].Get_Player_Age())
		{
			int temp2= player[i + 1].Get_Player_Age();
			string temp3 = player[i + 1].Get_Player_Name();
			player[i + 1].Set_Player_Age(player[i].Get_Player_Age());
			player[i + 1].Set_Player_Name(player[i].Get_Player_Name());
			player[i].Set_Player_Age(temp2);
			player[i].Set_Player_Name(temp3);
		}
	}
	//Setup the game board for playing
	Ingredients *ing = new Ingredients;
	ing->Centre_Ingredients();
	game->GameSetup();

	//Game Menu 

	int choice1;
	cout << "Enter 1 to play Game " << endl;
	cout << "Enter 0 to Quit Game" << endl;
	cin >> choice1;
	while (game->Check_Win()==false )
	{
		do {
			for (int i = 0; i < p; i++)
			{
				system("cls");
				cout << "Now the Turn is of player: " << player[i].Get_Player_Name() << endl;
				game->Roll_Action_Dice();
				if (game->Check_Win() == true)
				{
					choice1== 0;
					cout << "The Game has been ended." << endl;
					return(0);
					break;
				}
				cout << "Now the turn is of Next player" << endl;
				cout << "Press 1 to continue the Game." << endl;
				cout << "Press 2 to Display the board of the game" << endl;
				cout << "press 0 to Quit the Game." << endl;
				
				

				cin >> choice1;
				if (choice1 == 2)
				{
					game->Display_Board();
					cout << "Press any key to continue the game" << endl;
					system("pause");
				}
				if (choice1 == 0)
				{
					return(0);
				}
			}
		} while (choice1 == 1);
		if (choice1 == 0)
		{
			system("cls");
			cout << "Game Ended" << endl;
			system("pause");
			return(0);
			break;
		}
	}
	
	system("pause");
	return 0;
}

	