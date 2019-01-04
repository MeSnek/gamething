// game v2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "stdlib.h"

char gameboard [5] [5];

void setGameBoard();
void characterMovement();
void drawGameBoard();
int findPlayerYPosition ();
int findPlayerXPosition();

int main()
{
	setGameBoard();
}
//function that sets board as *
void setGameBoard()
{
	//puts * at all coords
	for (int i = 0; i < 5; i++)
	{
		gameboard [0] [i] = '*';
		gameboard [1] [i] = '*';
		gameboard [2] [i] = '*';
		gameboard [3] [i] = '*';
		gameboard [4] [i] = '*';
		//draw player
	}
	gameboard[2][2] = 'O';
	drawGameBoard();
}

//draws gameboard
void drawGameBoard()
{
	system("CLS");
	//prints gameboard
	for (int i = 0; i < 5; i++)
	{
		std::cout << gameboard[0][i];
	}
	std::cout << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << gameboard[1][i];
	}
	std::cout << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << gameboard[2][i];
	}
	std::cout << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << gameboard[3][i];
	}
	std::cout << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << gameboard[4][i];
	}
	std::cout << std::endl;
	//calls characterMovement
	characterMovement();
}

void characterMovement()
{
	char playerinput;
	std::cout << "W/A/S/D to move" << std::endl;
	std::cin >> playerinput;
	
	if (playerinput == 'W' || playerinput == 'w')
	{	
		int x = findPlayerXPosition();
		int y = findPlayerYPosition();
		gameboard [y] [x] = '*';
		gameboard [y - 1] [x] = 'O';
		drawGameBoard();
	}
	else if (playerinput == 'A' || playerinput == 'a')
	{
		int x = findPlayerXPosition();
		int y = findPlayerYPosition();
		gameboard[y][x] = '*';
		gameboard[y][x - 1] = 'O';
		drawGameBoard();
	}
	else if (playerinput == 'S' || playerinput == 's')
	{
		int x = findPlayerXPosition();
		int y = findPlayerYPosition();
		gameboard[y][x] = '*';
		gameboard[y + 1][x] = 'O';
		drawGameBoard();
	}
	else if (playerinput == 'D' || playerinput == 'd')
	{
		int x = findPlayerXPosition();
		int y = findPlayerYPosition();
		gameboard[y][x] = '*';
		gameboard[y][x + 1] = 'O';
		drawGameBoard();
	}
}

int findPlayerYPosition()
{
	int x = 0;
	int y = 0;
	int findx = 0;
	//find x and y
	for (int findy = 0; findy < 5; findy++)
	{
		char checker = gameboard[findy][findx];
		if (checker == 'O')
		{
			y = findy;
			x = findx;
			return y;
		}
		else if (findy == 4)
		{
			findx++;
			findy = 0;
		}
	}
}

int findPlayerXPosition()
{
	int x = 0;
	int y = 0;
	int findx = 0;
	//find x and y
	for (int findy = 0; findy < 5; findy++)
	{
		char checker = gameboard[findy][findx];
		if (checker == 'O')
		{
			y = findy;
			x = findx;
			return x;
		}
		else if (findy == 4)
		{
			findx++;
			findy = 0;
		}
	}
}