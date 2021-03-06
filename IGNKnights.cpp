/*
 *  IGNKnights.cpp
 *  
 *
 *  Created by Max Corman on 5/20/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

/*
 
 This is my program to find the minimum number of moves.
 
 It starts off by using Djikstra's theorem to find the quickest
 number of moves for a knight to get from one spot to every
 other spot. It does this for all 64 spots on the chessboard.
 
 Then, I use a dynamic programming algorithm to find the 
 minimum number of moves it takes for the knight to land
 on every spot. This is done by finding the move that requires 
 the least amount of moves. 
 
 Unfortuantly, I could not come up with a way to store already
 calculated values, so this program has very poor run time. From
 what I can tell, my solution here calculates every possible 
 combination of moves and then prints out the minimum. I was 
 unable to calculate the minimum number of moves.
 
 
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
	
	//cout << "Done with Djikstra" << endl;
	// Find the shortest number of moves
	int min = -1;
	int dummy = -1;
	start.xVal = 0;
	start.yVal = 0;
	level = 0;
	
	bool touched[COLUMNS][ROWS];
	InitTouched(touched);
	
	//cout << "Done initializing" << endl;
	
	// now actually start looking for shortest path
	for (int i = 0; i < COLUMNS; i = i + 1)
	{
		start.xVal = 0;
		for (int j = 0; j < ROWS; j = j + 1)
		{
			start.yVal = j;
			level = Hash(start.xVal, start.yVal);
			dummy = FindShortest(board, level, start, 0, touched, start);
			cout << "Done with i = " << i << ", j = " << j << "!" << endl;
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
	
	/*
	for (int i = 0; i < (ROWS*COLUMNS); i = i + 1)
	{
		cout << "Level " << i << endl;
		Print(board[i]);
		cout << endl;
	}
	*/
	
	
	
	//cout << board[14][3][1].num_of_moves << endl;
	
	
	return 0;
	
}










