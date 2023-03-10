#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include "TicTacToe.h"
#include "ConsoleExtension.h"

using namespace std;

int main(VOID)
{

	bool exitGame = false;

	TicTacToe ttt = TicTacToe(1);
	int currentState = 1;
	ttt.render();

	while (!exitGame) {

		cout << "\n\n\n";

		int x = 0, y = 0;
		int winnerState = 0;

		do {
			if (ttt.checkForEnd(&winnerState)) {
				break;
			}

			cout << "Current player: " << (currentState == 1 ? ttt.Cross : ttt.Circle) << endl;
			cout << "Select cell: ";
			cin >> x >> y;

			x--;
			y--;
		} while (!ttt.place(x, y, currentState));

		currentState = currentState == 1 ? 2 : 1;
		system("cls");
		ttt.render();

		if (ttt.checkForEnd(&winnerState)) {
			
			if (winnerState == 0)
				cout << "Tie"<<endl;
			else
				cout << "Winner: " << (winnerState == 1 ? ttt.Cross : ttt.Circle) << endl;

			cout << "Do you want to play one more time?" << endl;
			cout << "[y/n]: ";
			char answer;
			cin >> answer;

			if (answer == 'y' || answer == 'Y')
			{
				exitGame = false;
				currentState = 1;
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