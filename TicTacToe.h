//Sargis Karapetyan
//CSIS 137
//HW1

#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe{
public:
	TicTacToe();
	bool setTable(int, int, int);
	void displayTable();
	int isWin(int);					
	void clearTable();
private:
	int table[3][3];
};

#endif
