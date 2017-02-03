// ConsoleApplication3.cpp : Defines the entry point for the console application.
//



#include "stdafx.h"
#define ROCK 0
#define PAPER 1
#define SCISSORS 2

using namespace std;

void printChoice(int i);

int main()
{
	int playChoice = 3, compChoice = 0;
	string playChoiceChar;

	cout << "Welcome to Rock-Paper-Scissors! " << endl;

	/*	Decision matrix for player vs. computer
		Row = Player Choice
		Column = Computer Choice
		2 = Tie
		1 = Player Win
		0 = Computer Win */
	int decision[3][3] = { 2,0,1,1,2,0,0,1,2 };
	int wins = 0, loss = 0, draw = 0, result;

	do
	{
		// generate computer choice
		srand((unsigned int)time(NULL));
		compChoice = rand() % 3;
		
		/* Display options for user*/
		cout << endl << "Please enter your choice: " << endl;
		cout << "Rock - R" << endl;
		cout << "Paper - P" << endl;
		cout << "Scissors - S" << endl;
		cout << "Quit - Q" << endl << endl << "Choice: ";
		
		/* Read in user choice*/
		cin >> playChoiceChar;

		/* Assign appropriate choice, only reads first char*/
		switch (toupper(playChoiceChar[0])) {
		case 'R':
			playChoice = ROCK;
			break;
		case 'P':
			playChoice = PAPER;
			break;
		case 'S':
			playChoice = SCISSORS;
			break;
		case 'Q':
			return 0;
			break;
		default:
			playChoice = 3;		// 3 -> User did not choose correct input
			cout << endl << "Please choose one of the options." << endl;
			break;
		}

		if (playChoice != 3)
		{
			/* Print results */
			cout << endl << "You chose: ";
			printChoice(playChoice);
			cout << "Computer chose: ";
			printChoice(compChoice);

			cout << endl << "Result: ";
			result = decision[playChoice][compChoice];
			if (result == 0) {
				cout << "COMPUTER WIN!" << endl;
				loss++;
			}
			else if (result == 1){
				cout << "PLAYER WIN!" << endl;
				wins++;
			}
			else {
				cout << "DRAW!" << endl;
				draw++;
			}
			cout << endl << "Current Record: " << wins << "W-" << loss << "L-" << draw << "D" << endl;
			cout << endl << "------------------------------";
			
		}

	} while (1);
	
}

void printChoice(int i)
{
	switch (i)
	{
		case 0:
			cout << "Rock" << endl;
			break;
		case 1:
			cout << "Paper" << endl;
			break;
		case 2:
			cout << "Scissors" << endl;
			break;
		default:
			break;
	}
}
