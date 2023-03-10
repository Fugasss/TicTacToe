#pragma once

#include <iostream>
#include <Windows.h>
#include "ConsoleExtension.h"

using namespace std;

class TicTacToe
{
public:
	TicTacToe(int borderSize) : BorderSize(borderSize)
	{
		restart();
	}

	const char Cross = 'X';
	const char Circle = 'O';
	const int BorderSize; 
	
	bool place(int x, int y, int state);
	bool checkForEnd(int* winnerState);
	void render();
	void restart();

	int gameBoard[3][3];

private:
	int movesRemain;
};

