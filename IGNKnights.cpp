/*
 *  IGNKnights.cpp
 *  
 *
 *  Created by Max Corman on 5/20/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

/*
 
 You can just make not visited a boolean!!!
 
 The variable i stands for columns and the 
 variable j stands for rows. You have it
 backwards in your for loops. It doesn't matter
 now since both rows and columns = 8, but fix
 it soon!!!
 
 You'll need an array to keep track of what levels
 have been used already
 
 
 
*/



#include "IGNKnights.h"

using namespace std;

int main(void)
{
	// Declare the board
	spot ***board;
	board = new spot **[ROWS*COLUMNS];
	for (int i = 0; i < (ROWS*COLUMNS); i = i + 1)
	{
		board[i] = new spot *[COLUMNS];
		for (int j = 0; j < COLUMNS; j = j + 1)
		{
			board[i][j] = new spot[ROWS];
		}
	}
	
	
	spot start;
	start.xVal = 0;
	start.yVal = 0;
	
	// Use Djikstra's to find the fastest way to each spot
	// from every other spot on the board. All source
	// shortest path
	int level = 0;
	for (int i = 0; i < COLUMNS; i = i + 1)
	{
		start.xVal = i;
		for (int j = 0; j < ROWS; j = j + 1) 
		{
			start.yVal = j;
			Djikstra(start, board[level]);
			level = level + 1;
		}
	}
	
	cout << "Done with Djikstra" << endl;
	// Find the shortest number of moves
	int min = -1;
	int dummy = -1;
	start.xVal = 0;
	start.yVal = 0;
	level = 0;
	
	bool touched[COLUMNS][ROWS];
	InitTouched(touched);
	
	cout << "Done initializing" << endl;
	
	// now actually start looking for shortest path
	for (int i = 0; i < COLUMNS; i = i + 1)
	{
		start.xVal = 0;
		for (int j = 0; j < ROWS; j = j + 1)
		{
			start.yVal = j;
			level = Hash(start.xVal, start.yVal);
			dummy = FindShortest(board, level, start, 0, touched, start);
			
			if (min < 0 || dummy < min)
			{
				min = dummy;
			}
		}
	}
	
	// print the minimum number of moves needed
	cout << "Minimum number of moves needed is... " << min << endl << endl;
	
	/*
	spot test;
	test.xVal = 3;
	test.yVal = 2;
	int i = Hash(3,2);
	Print(board[i]);
	*/	
	
	
	for (int i = 0; i < (ROWS*COLUMNS); i = i + 1)
	{
		cout << "Level " << i << endl;
		Print(board[i]);
		cout << endl;
	}
	
	
	
	
	cout << board[14][3][1].num_of_moves << endl;
	
	
	return 0;
	
}










