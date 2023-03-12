#pragma once

#include <iostream>
#include <tuple>
#include "CellState.h"
#include "TicTacToe.h"
#include <algorithm>
#include <cmath>

using std::pair;
using std::make_pair;
using std::copy_n;
using std::min;
using std::max;

class Bot
{
public:
	Bot(CellState playState, TicTacToe* ttt) : PlayState(playState), Ttt(ttt){}
	
	const CellState PlayState;

	pair<int,int> makeMove();

private:
	TicTacToe* Ttt;
	int minimax(int depth, bool isMax);
};

