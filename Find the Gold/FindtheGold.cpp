// FindtheGold.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string> 
#include <cmath>
#include <limits>
#include <time.h>
#include <iomanip>
using namespace std;

#define Size 8


 
//Building Initial Board so players can see how it looks
void InitBoard()
{

	cout << "  1   2   3   4   5   6   7   8" << endl;
	cout << "  ______________________________" << endl;


	for (int y = 0; y < 8; y++)
	{
		cout << y + 1 << '|';
		for (int x = 0; x < 8; x++)
		{
			cout << "?   ";

		}
		cout << endl;
	}
};

//Style points for making the sign 
void StylePoints()
{

	cout << "********************************" << endl;
	cout << "**        Find Gold           **" << endl;
	cout << "**     You have 5 Guesses     **" << endl;
	cout << "**      5 pieces of Gold      **" << endl;
	cout << "**         and 1 bomb         **" << endl;
	cout << "**        Goodbluck           **" << endl;
	cout << "**                            **" << endl;
	cout << "*********************************" << endl;

	cout << endl;
}

// Function for building the gameboard and inputing values for both X coordinate and Y coordinate
 void BoardBuilder()
{
	int bombs = 0;
	char X, Y;
	int xCoord;
	int yCoord;
	int guesses = 5;
	int gold = 0;
	char gameBoard[Size][Size] = { 0 };
	int goldCount = 0;



	srand((unsigned)time(0));

	do
	{
		do
		{
			X = rand() % Size;
			Y = rand() % Size;

		} while (gameBoard[X][Y] != 0);
		gameBoard[X][Y] = 'B';

		bombs++;

	} while (bombs < 1);

	//Do while loop making the bomb for the game

	do
	{

		do
		{
			X = rand() % Size;
			Y = rand() % Size;

		} while (gameBoard[X][Y] != 0);
		gameBoard[X][Y] = 'G';

		gold++;


	} while (gold < 5);
	//DO while loop for making the gold for the game

	do
	{
		cout << "Enter x Coordinate: ";
		cin >> xCoord;
		cout << "Enter y Coordinate: ";
		cin >> yCoord;
		guesses--;

		char guess = gameBoard[xCoord][yCoord];

		switch (guess) {

		case 'B': 
		{	 guesses = 0;
		cout << " You lose idiot";
		break;

		}
		case 'G':
		{   gameBoard[xCoord][yCoord] = 'F';
		guesses++;
		cout << "Yay you got some gold!! You have "<<guesses << " to go" << endl;
		
		goldCount++;
		break;

		}// case that makes it if you find a gold you get an extra turn
		
		 default: cout << "Too Bad...  you have " << guesses << " to  go! " << endl;


		}

		//Switch Case for inputed answers 

	} while (guesses > 0);

	cout << endl;
	if (goldCount != 0)
	{
		cout << "Nice you got " << goldCount << " Point(s)!!!" << endl;
	}
	else
	{
		cout << "No points for you friend" << endl;
	}
	
	cout << "  1   2   3   4   5   6   7   8" << endl;
	cout << "  ______________________________" << endl;
	for (X = 0; X < Size; X++)
	{
	
		cout << X + 1 << '|';
		for (Y = 0; Y < Size; Y++)
		{

			cout << gameBoard[X][Y] <<"   ";
		}
		
		cout << endl;
	}

	//Printing of the final game board 
	
	

}






int main()
{
	bool cont = false;
	char answer;
	InitBoard();
	StylePoints();
	do {
		BoardBuilder();

		cout << "Do you want to Play more? Enter 'Y' "; 
		cin >> answer;

		if (answer == 'Y' || answer=='y')
		{
			cont = true;
		}
		else if (answer == 'N' || answer == 'n')
		{
			cont = false;
		}
			
	} while (cont);
	//Loop for asking users if they would like to continue to play the game.


	
    return 0;
}

