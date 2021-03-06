#include "TicTacToe.h"
#include <iostream>

using namespace std;

TicTacToe::TicTacToe(){				//sets the default table to 0
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			table[i][j] = 0;
		}
	}
}

void TicTacToe::displayTable(){								//dispays the table
	for (int i = 0; i < 3; i++){
		cout << "Row\n" << i+1 << "\t";
		for (int j = 0; j < 3; j++){
			cout << table[i][j];
		}
		cout << endl;
	}
}

bool TicTacToe::setTable(int num, int r, int c){
	if (table[r][c] != 0){
		return false;
	}
	else{
		table[r][c] = num;
		return true;
	}
}


int TicTacToe::isWin(int num){				//int number of the player
	int value=0;
	for (int i = 2; i >=0; i--){
		if (table[0][i]==num && table[1][i] == num && table[2][i] == num){				//vertical
			value= 1;
		}
		if (table[i][0] == num && table[i][1] == num && table[i][2] == num){		//horizontal 
			value = 1;
		}
	}		
	if (table[0][0] == num && table[1][1] == num && table[2][2] == num){			//diagonal 1
		value = 1;
	}
	if (table[2][0] == num && table[1][1] == num && table[0][2] == num){			//diagonal 
		value = 1;
	}

	return value;
}

void TicTacToe::clearTable(){
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			table[i][j] = 0;
		}
	}
}
