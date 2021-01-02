#include<iostream>
#include"ingredients.cpp"
using namespace std;

class Game {
	
public:
	Ingredients *Action_dice = new Ingredients;
	Ingredients *iobj = new Ingredients;
	int Revealed[6];
	int BlockedPaths[6] = { 1,1,1,1,1,1 };
	int Reached[6] = { -3,-3,-3,-3,-3,-3 };
	int revealed = 0;
	int blockedpaths = 0;
	int board[6][10];
	Game(){} //Default Constrctor
	void Set_Board()
	{
		for (int i = 0; i < 6; i++)
		{
			for (int j = 1; j < 10; j++)
			{
				board[i][0] = i;
				board[i][j] = -1;
			}
		}
	}
	void Display_Board()
	{
		system("cls");

		cout << "-------------------------Game Board---------------------------------" << endl;
		cout << endl;
		for (int i = 0; i < 6; i++)
		{
			cout << "[ ";
			for (int j = 0; j < 10; j++)
			{
				cout<< board[i][j]<< "  ";
			}
			cout << "]";
			cout << endl;
		}
		cout << endl;
		cout << "--------------------------------------------------------------------" << endl;
	}

	int Roll_Dice()
	{
		srand(time(NULL));
		int random = rand ()% 6 + 1;
		return random;
	}

	bool CheckReveal(int number)
	{
		if (revealed > 5)
		{
			revealed = 5;
		}
		for (int i = 0; i < revealed; i++)
		{
			if (number == i)
			{
				return true;
			}
		}
		return false;
	}

	void Move_Bottle(int number,int steps)
	{

		while (steps > 0)
		{
			for (int j = 0; j < 10; j++)
			{
				if (j == 7)
				{
					continue;
				}
				if (steps == 0)
				{
					return;
					break;
				}
				if (j == 6 && board[number][j] != -1)
				{
					int temp = board[number][j+2];
					board[number][j+2] = board[number][j];
					board[number][j] = temp;
					steps--;

				}

				else if (board[number][j] != -1 && j < 9)
				{
					int temp = board[number][j + 1];
					board[number][j + 1] = board[number][j];
					board[number][j] = temp;
					steps--;
				}
				if (j == 9 && board[number][j] != -1 && steps > 0 && CheckReveal(number)==true)
				{
					Reached[number] = 1;
					board[number][9] = -1;
					cout << "congratulations! The Potion bottle has reached in the centre" << endl;
					steps--;
					
					return;
					break;
					
					steps--;
				}
			}
		}
	}

	bool Blocked(int bottle)
	{
		for (int i = 0; i < 10; i++)
		{
			if (board[bottle][7] == -2)
			{
				return true;
			}
			else
				return false;
		}
	}

	bool Check_Win()
	{
		//if all the paths are blocked wizard has won
		int blockcount=0;
		for (int i = 0; i < 6; i++)
		{
			if (BlockedPaths[i] == -2)
			{
				blockcount++;
			}
		}
		if (blockcount == 6)
		{
			cout << "Alas! The Wizard has won the game." << endl;
			
			return true;

		}
		int sum = 0;
		
		for (int j = 0; j < 6; j++)
		{
			if (Reached[j] == 1)
			{
				sum++;
			}
		}	
		if (sum < 3)
		{
			return false;
		}
		if (sum > 3)
		{
			sum = 0;
			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (Reached[i] == 1 && CheckReveal(i)==true)
					{
						if (iobj->Potion_Bottles[i] == iobj->centre[j])
						{
							sum++;
						}
					}
				}
			}
			if (sum == 3)
			{
				cout << "You have won the game" << endl;
				return true;
			}
			else
			{
				return false;
			}
		}
		
	}

	void Roll_Magic_Dice()
	{
		int Magics[3];
		system("cls");
		cout << "Press 1 to Reveal Charm" << endl;
		cout << "Press 2 to use Swap Charm " << endl;
		cout << "Press 3 to use Super Power Charm" << endl;
		int option;
		cout << "Enter your option: ";
		cin >> option;
		int sum = 0;
		switch (option)
		{
		case(1):
			system("cls");
			if (revealed > 5)
			{
				cout << "All the bottles are already reveled." << endl;
				break;
			}
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0;j < 3; j++)
				{
					Magics[j] = Roll_Dice();
					if (Magics[j] % 2 == 0)
					{
						Magics[i] = Magics[j];
						break;
					}
				}
			}
			for (int i = 0; i < 3; i++)
			{
				if (Magics[i] % 2 != 0)
				{
					cout << "Sorry you cannot Reveal Charm. " << endl;
					break;
				}
				else if (Magics[i] % 2 == 0)
				{
					sum += 1;
				}
			}
			if (sum == 3)
			{
				cout << "You can use Reveal Charm. The Reveal Charm allows you to turn the Potion Bottle ingredient side up. " << endl;
				
			}
			
				

			break;
		case(2):
			//Swap charms
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					Magics[j] = Roll_Dice();
					if (Magics[j] % 2 != 0)
					{
						Magics[i] = Magics[j];
						break;
					}
				}
			}
			for (int i = 0; i < 3; i++)
			{
				if (Magics[i] % 2 == 0)
				{
					cout << "Sorry you cannot Swap Charm. Reason is you are out of moves and odd number did not appear." << endl;
					break;
				}
				else if (Magics[i] % 2 != 0)
				{
					sum += 1;
				}
			}
			if (sum == 3)
			{
				system("cls");
				cout << "You can use Swap Charm. Swap any potion bottle with other. " << endl;
				
				
				string temp;
				int first;
				int second;
				cout << "Enter first bottle number ( 1 to 6 inclusive)";
				cin >> first;
				cout << "Enter the second bottle number ( 1 to 6 inclusive)";
				cin >> second;
				first = first - 1;
				second = second - 1;
				int count = 0;
				while (Reached[first] != -3 || Reached[second] != -3)
				{
					if (count > 3)// Maximum 3 times player can enter the number of bottles to swap;
					{
						break;
					}
					cout << "Following bottles can be swapped with each other." << endl;
					for (int i = 0; i < 6; i++)
					{
						if (Reached[i] == -3)
						{
							cout << iobj->Potion_Bottles[i] << endl;
						}
					}
					count += 1;
					if (Reached[first] != -3)
					{
						cout << "The bottle" << first + 1 << " is already in the centre. You cannot swap with it." << endl;
						cout << "Enter the number of first bottle again (1 to 6)" << endl;
						cin >> first;
						first = first - 1;
					}
					else if (Reached[second] != -3)
					{
						cout << "The bottle" << second + 1 << " is already in the centre. You cannot swap with it." << endl;
						cout << "Enter the number of second bottle again( 1 to 6) " << endl;
						cin >> second;
						second = second - 1;
					}
				}
				
				int c1, c2;
				for (int j = 0; j < 10; j++)
				{
					if (board[first][j] != -1)
					{
						c1 = j;
					}
					if (board[second][j] != -1)
					{
						c2 = j;
					}
				}

				int temp1 = board[second][c2];
				board[second][c2] = board[first][c1];
				board[first][c1] = temp1;
				cout << "Bottle " << first + 1 << " has been swapped with" << second + 1 << " bottle." << endl;


			}



			break;
		case(3):
			//Super PowerCharm
			for (int i = 0; i < 3; i++)
			{
				int sum = 0;
				for (int j = 0; j < 3; j++)
				{
					sum += Roll_Dice();

				}
				if (sum == 12)
				{
					int bottle;
					cout << "Congratulation! You can use Super Power Charm" << endl;
					cout << "Enter the bottle number(1 to 6) you want to move 6 steps :";
					cin >> bottle;
					Move_Bottle(bottle - 1,6);
					
				}
			}
			break;
		default:
			break;
		}
	}
	bool BlockPath(int number)
	{
		int count = 0;
		for (int i = 0; i < 6; i++)
		{
			if (BlockedPaths[i] == -2)
			{
				count++;
			}

		}
		if (count == 6)
		{
			cout << "Oh! Wizard has won the game." << endl;
			return false;
		}
		else
		{
			BlockedPaths[blockedpaths] = -2;
			
			board[blockedpaths][7] = -2;
			blockedpaths++;
			return true;
		}
	}
	void GameSetup()
	{
		Set_Board();
		Display_Board();

	}
	void Roll_Action_Dice()
	{
		int bottleNo;
		string A1;
		string A2;
		srand(time(NULL));
		int random = rand() % 6 + 1;
		A1=Action_dice->A1_Dice[random];
		int random3 = rand() % 6 + 1;
		A2=Action_dice->A2_Dice[random3];
		if (A1 == "potion" && A2=="3")
		{
			cout << "Move the Potion Bottle";
			cout << "Enter the bottle number you want to move (1 to 6) : ";
			cin >> bottleNo;
			bottleNo = bottleNo - 1;
			if (Blocked(bottleNo) == false )
			{
				Move_Bottle(bottleNo, 1);
			}
			
		}
		
		else if (A1 == "wizard's hat" && A2 == "Lightning")
		{
			cout << "Path "<<blockedpaths+1<<" is blocked." << endl;
			BlockPath(blockedpaths);
			system("pause");

		}
		else if (A1 == "potion" && A2 == "Lightning")
		{
			int choice;
			cout << "Roll the Magic Dice" << endl;
			cout << "Press 1 to Roll Magic Dice" << endl;
			cin >> choice;
			if (choice == 1)
			{
				Roll_Magic_Dice();
			}
		}
		else {
			cout << "You Rolled Action Dices but no action option is valid for you." << endl;

		}

	}
	
};