#pragma once

#include <iostream>
#include "ConsoleExtension.h"
#include "CellState.h"

using namespace std;

class TicTacToe
{
public:
	TicTacToe(int borderSize) : BorderSize(borderSize)
	{
		restart();
	}

	static const char Cross = 'X';
	static const char Circle = 'O';
	const int BorderSize; 
	
	bool place(int x, int y, CellState state);
	bool checkForEnd(CellState* winnerState);
	void render();
	void restart();

	static const char StateToChar(CellState state);

	CellState gameBoard[3][3];

private:
	int movesRemain;
};

