#pragma once

#include "TicTacToe.h"
#include "ConsoleExtension.h"
#include "CellState.h"
#include <iostream>

using std::cout;
using std::endl;


class TicTacToeView
{
public:
	TicTacToeView(int borderSize) : _borderSize(borderSize) {}

	void render(CellState board[3][3]);

private:
	const int _borderSize;
};

