#include <iostream>
#include <Windows.h>
#include "TicTacToe.h"
#include "ConsoleExtension.h"
#include "CellState.h"

using namespace std;

int main(VOID)
{
	bool exitGame = false;

	TicTacToe ttt = TicTacToe(1);
	CellState currentState = CellState::Cross;
	ttt.render();

	while (!exitGame) {

		cout << "\n\n\n";

		int x = 0, y = 0;
		CellState winnerState = CellState::None;

		do {
			if (ttt.checkForEnd(&winnerState)) {
				break;
			}

			cout << "Current player: " << TicTacToe::StateToChar(currentState) << endl;
			cout << "Select cell: ";
			cin >> x >> y;

			x--;
			y--;
		} while (!ttt.place(x, y, currentState));

		currentState = currentState == CellState::Cross ? CellState::Circle : CellState::Cross;
		system("cls");
		ttt.render();

		if (ttt.checkForEnd(&winnerState)) {

			if (winnerState == CellState::None)
				cout << "Tie" << endl;
			else
				cout << "Winner: " << TicTacToe::StateToChar(winnerState) << endl;

			cout << "Do you want to play one more time?" << endl;
			cout << "[y/n]: ";
			char answer;
			cin >> answer;

			if (answer == 'y' || answer == 'Y')
			{
				exitGame = false;
				currentState = CellState::Cross;
				ttt.restart();
				system("cls");
				ttt.render();
			}
			else
			{
				exitGame = true;
			}
		}
	}



	return 0;
}