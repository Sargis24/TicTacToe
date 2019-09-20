//Sargis Karapetyan
//CSIS 137
//HW1

#include "TicTacToe.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int row, col, player = 0;
	int temp = 0;
	int winner = 0;
	char selection;
	int draw = 9;
	string player1, player2;
	TicTacToe game;

	do
	{
		cout << "Welcome to the Tic Tac Toe game." << endl
			<< "Press 1, to play." << endl
			<< "Press 'Q' to quit." << endl;
		cin >> selection;
		cin.ignore();

		if (selection == '1')
		{
			TicTacToe();

			cout << "\nPlease enter 1st player name" << endl;
			getline(cin, player1);
			cout << "Please enter 2nd player name" << endl;
			getline(cin, player2);
			cout << endl;


			do
			{
				game.displayTable();
				cout << endl << player1 << ", please enter the number of ROW (1 to 3)" << endl;
				cin >> temp;
				while (temp < 1 || temp>3)
				{
					cout << "The number of rows cannot be less than 1 and greater than 3." << endl;
					cout << "Please reselct the row." << endl;
					cin >> temp;
				}
				row = temp - 1;
				cout << player1 << ", please enter the COLUMN (1 to 3)" << endl;
				cin >> temp;
				cout << endl;
				while (temp < 1 || temp>3)
				{
					cout << "The number of rows cannot be less than 1 and greater than 3." << endl;
					cout << "Please reselct the row." << endl;
					cin >> temp;
				}
				col = temp - 1;
				cout << endl;
				while (game.setTable(1, row, col) == false)
				{
					cout << "That box is taken. Please reselect the box." << endl;
					cout << player1 << ", please enter the number of ROW (1 to 3)" << endl;
					cin >> temp;
					row = temp - 1;
					cout << player1 << ", please enter the COLUMN (1 to 3)" << endl;
					cin >> temp;
					col = temp - 1;
				}
				if (game.isWin(1) == 1)
				{
					winner = 1;
					cout << endl << player1 << ", WINS!" << endl;
				}
				else
				{
					draw--;
					if (draw == 0)
					{
						winner = 1;
						cout << "It's a TIE.\n" << endl;
					}
					else
					{
						game.displayTable();
						cout << endl<<player2 << ", please enter the number of ROW (1 to 3)" << endl;
						cin >> temp;
						row = temp - 1;
						cout << player2 << ", please enter the COLUMN (1 to 3)" << endl;
						cin >> temp;
						cout << endl;
						col = temp - 1;
						while (game.setTable(2, row, col) == false)
						{
							cout << "That box is taken. Please reselect the box." << endl;
							cout << player2 << ", please enter the number of ROW (1 to 3)" << endl;
							cin >> temp;
							row = temp - 1;
							cout << player2 << ", please enter the COLUMN (1 to 3)" << endl;
							cin >> temp;
							col = temp - 1;
						}
						if (game.isWin(2) == 1)
						{
							winner = 2;
							cout << endl<<player2 << ", WINS!" << endl;
							game.clearTable();
						}
						else
						{
							draw--;
							if (draw == 0)
							{
								winner = 1;
								cout << "It's a TIE." << endl;
							}

						}
					}

				}
			} while (winner == 0);
		}
		else if (selection != '1' && selection != 'q' && selection != 'Q')
			{
				cout << "Invalid selection. Try again." << endl;
			}
		game.clearTable();
		winner = 0;
		draw = 9;
	} while (selection != 'q' && selection != 'Q');
	system("pause");
	return 0;
}