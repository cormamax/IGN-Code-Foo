/*
 *  IGNKnights.h
 *  
 *
 *  Created by Max Corman on 5/20/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include <iostream>
#include <string>
#include "Queue.cpp"

using namespace std;

struct spot 
{
	int xVal;
	int yVal;
	int num_of_moves;
	//bool touched;
	
};	

const int ROWS = 4;
const int COLUMNS = 4;
const int NOT_VISITED = -1;

void Initialize(spot **board);
void Djikstra(spot current, spot **board);
void Print(spot **board);
int FindShortest(spot ***board, int level, spot current, int total_moves, 
				 bool touched[COLUMNS][ROWS], spot prev);
int Hash(int i, int j);
void InitTouched(bool touched[COLUMNS][ROWS]);
bool CheckDone(bool touched[COLUMNS][ROWS]);


void Djikstra(spot current, spot **board)
{	// when called, current is the start location on the board 
	// because each "edge" is this graph is 1, when you enqueue 
	// it, it is going to be the fastest way to get there, therefore
	// you do not see to search for the smallest value. It will
	// always be your next one.
	
	/* 
	 
	 board looks like this
		i
	  01234567
	0 ........
	1 ........
	2 ........ 
 j	3 ........ 
	4 ........
	5 ........
	6 ........ 
	7 ........
	 
	*/
	
	// First, initialize board
	Initialize(board);
	
	// Set starting location
	board[current.xVal][current.yVal].num_of_moves = 0;
	current = board[current.xVal][current.yVal];	
	
	
	ArrayQueue<spot> queue(ROWS*COLUMNS);
	queue.enqueue(current);
	
	//spot neighbor;
	while (queue.empty() == false) 
	{
		current = queue.dequeue();
		
		//cout << "x = " << current.xVal << ", y = " << current.yVal << endl;
		//cout << "num of moves = " << current.num_of_moves << endl << endl;
		// for each neighbor of the item, check and
		// add neighbors to queue
		
		// check right 2 and up 1
		if (current.xVal + 2 < COLUMNS && current.yVal - 1 >= 0 &&
			board[current.xVal + 2][current.yVal - 1].num_of_moves == NOT_VISITED)
		{
			board[current.xVal + 2][current.yVal - 1].num_of_moves =
				current.num_of_moves + 1;
			queue.enqueue(board[current.xVal + 2][current.yVal - 1]);
		}
		// check right 2 and down 1
		if (current.xVal + 2 < COLUMNS && current.yVal + 1 < ROWS &&
			board[current.xVal + 2][current.yVal + 1].num_of_moves == NOT_VISITED)
		{
			//cout << "in here" << endl;
			board[current.xVal + 2][current.yVal + 1].num_of_moves =
				current.num_of_moves + 1;
			queue.enqueue(board[current.xVal + 2][current.yVal + 1]);
		}
		// check up 2 and right 1
		if (current.xVal + 1 < COLUMNS && current.yVal - 2 >= 0 &&
			board[current.xVal + 1][current.yVal - 2].num_of_moves == NOT_VISITED)
		{
			board[current.xVal + 1][current.yVal - 2].num_of_moves =
				current.num_of_moves + 1;
			queue.enqueue(board[current.xVal + 1][current.yVal - 2]);
		}
		// check up 2 and left 1
		if (current.xVal - 1 >= 0 && current.yVal - 2 >= 0 &&
			board[current.xVal - 1][current.yVal - 2].num_of_moves == NOT_VISITED)
		{
			board[current.xVal - 1][current.yVal - 2].num_of_moves =
				current.num_of_moves + 1;
			queue.enqueue(board[current.xVal - 1][current.yVal - 2]);
		}
		// check left 2 and up 1
		if (current.xVal - 2 >= 0 && current.yVal - 1 >= 0 &&
			board[current.xVal - 2][current.yVal - 1].num_of_moves == NOT_VISITED)
		{
			board[current.xVal - 2][current.yVal - 1].num_of_moves =
				current.num_of_moves + 1;
			queue.enqueue(board[current.xVal - 2][current.yVal - 1]);
		}
		// check left 2 and down 1
		if (current.xVal - 2 >= 0 && current.yVal + 1 < ROWS &&
			board[current.xVal - 2][current.yVal + 1].num_of_moves == NOT_VISITED)
		{
			board[current.xVal - 2][current.yVal + 1].num_of_moves =
				current.num_of_moves + 1;
			queue.enqueue(board[current.xVal - 2][current.yVal + 1]);
		}
		// check down 2 and left 1
		if (current.xVal - 1 >= 0 && current.yVal + 2 < ROWS &&
			board[current.xVal - 1][current.yVal + 2].num_of_moves == NOT_VISITED)
		{
			board[current.xVal - 1][current.yVal + 2].num_of_moves =
				current.num_of_moves + 1;
			queue.enqueue(board[current.xVal - 1][current.yVal + 2]);
		}
		// check down 2 and right 1
		if (current.xVal + 1 < COLUMNS && current.yVal + 2 < ROWS &&
			board[current.xVal + 1][current.yVal + 2].num_of_moves == NOT_VISITED)
		{
			board[current.xVal + 1][current.yVal + 2].num_of_moves =
				current.num_of_moves + 1;
			queue.enqueue(board[current.xVal + 1][current.yVal + 2]);
		}
		
		
		//Print(board);
		//cout << endl;
	}
	return;
}

void Initialize(spot **board)
{
	// initialize values
	for (int i = 0; i < COLUMNS; i = i + 1)
	{
		for (int j = 0; j < ROWS; j = j + 1)
		{
			board[i][j].xVal = i;
			board[i][j].yVal = j;
			board[i][j].num_of_moves = NOT_VISITED;
			//board[i][j].touched = false;
		}
	}
}

void Print(spot **board)
{
	/* 
	 
	 board looks like this
	 i
	 01234567
	 0 ........
	 1 ........
	 2 ........ 
	 j	3 ........ 
	 4 ........
	 5 ........
	 6 ........ 
	 7 ........
	 
	 */
	
	for (int j = 0; j < ROWS; j = j + 1)
	{
		for (int i = 0; i < COLUMNS; i = i + 1)
		{
			cout << board[i][j].num_of_moves << " ";
		}
		cout << endl;
	}
	
	/*
	for (int j = 0; i < COLUMNS; i = i + 1)
	{
		for (int j = 0; j < ROWS; j = j + 1)
		{
			cout << board[i][j].num_of_moves << " ";
		}
		cout << endl;
	}
	*/
}






int FindShortest(spot ***board, int level, spot current, int total_moves, 
				 bool touched[COLUMNS][ROWS], spot prev)
{	// touched[][] is a 2D array of booleans that is the same
	// size as the board. It lets you know if you have already 
	// visited a level. This tells you that that spot have been
	// visited.
	// level is the level that corresponds with current
	
	cout << "current Loc... ";
	cout << "x = " << current.xVal << ", y = " << current.yVal << endl;
	//cout << "in FindShortest, level = " << level << endl;
	// Base Case 
	touched[current.xVal][current.yVal] = true;
	if (CheckDone(touched))
	{	// return the number of moves it took to get to this spot
		// from its previous spot
		//cout << "in base case" << endl;
		//cout << "took... " << board[level][prev.xVal][prev.yVal].num_of_moves << endl;
		//cout << "level for this spot..." << endl;
		//Print(board[level]);
		//cout << "returned... " << board[level][prev.xVal][prev.yVal].num_of_moves << endl;
		touched[current.xVal][current.yVal] = false;

		return board[level][prev.xVal][prev.yVal].num_of_moves;
	}
	
	
	
	int prevLevel = level;
	
	
	// make a copy of the spot passed in
	spot init_spot = current;
	
	int min = -1;	// arbitrary value, you have not found the min yet
	spot min_spot;
	int dummy = -1;	// used to find new values and compare with min
	
	for (int i = 0; i < COLUMNS; i = i + 1)
	{
		current.xVal = i;
		for (int j = 0; j < ROWS; j = j + 1)
		{
			current.yVal = j;
			if (touched[current.xVal][current.yVal] == false)
			{
				level = Hash(current.xVal, current.yVal);
				dummy = FindShortest(board, level, current, total_moves, touched, init_spot);
				
				if (min < 0 || dummy < min)
				{
					min = dummy;
					min_spot.xVal = current.xVal;
					min_spot.yVal = current.yVal;
				}
			}
		}
	}
	
	// need to tell the boolean 2D array that we havn't been to that spot
	// really what happens is that when we come to this spot from a 
	// different square, we still want it to check it. 
	touched[init_spot.xVal][init_spot.yVal] = false;

	// increase the total moves it took to get to the spot
	//cout << "min = " << min << endl;
	//cout << endl << "You are at loc... ";
	//cout << "x = " << init_spot.xVal << ", y = " << init_spot.yVal << endl;

	//cout << "level for loc = " << endl;
	//Print(board[prevLevel]);

	//cout << "board level = " << prevLevel << endl;
	dummy = board[prevLevel][prev.xVal][prev.yVal].num_of_moves;
	//cout << "PrevLoc... x = " << prev.xVal << ", y = " << prev.yVal << endl;
	
	//cout << "min = " << min << endl;
	//cout << "dummy = " << dummy << endl;
	
	total_moves = total_moves + min + dummy;
	//cout << "total_moves = " << total_moves << endl;
	// return total moves
	return total_moves;
}




/*

int FindShortest(spot ***board, spot current, int &total_moves)
{
	// Check if done
	if (CheckDone(board))
	{	// if this is true, you want to return the
		// numbers of moves it took to get to this
		// spot from its previous spot
		
		
		
	}
	
	board[current.xVal][current.yVal].touched = true;
	
	for (int i = 0; i < COLUMNS; i = i + 1)
	{
		current.xVal = i;
		for (int j = 0; j < ROWS; j = j + 1) 
		{
			current.yVal = j;
			total_moves = FindShortest(board, current, total_moves)
		}
	}
	
	

}
*/
bool CheckDone(bool touched[COLUMNS][ROWS])
{	// Checks to see if every spot has been touched
	// returns false if any spot is false
	// returns true if all spots are true
	int i = 0;
	int j = 0;
	while (i < COLUMNS)
	{
		while (j < ROWS)
		{
			if (touched[i][j] == false)
			{
				return false;
			}
			else
			{
				j = j + 1;
			}
		}
		
		j = 0;
		i = i + 1;
	}
	
	//cout << "returned true!" << endl;
	return true;
}
/*
int Find(spot current, spot **board, int &total_moves)
{
	//board[current.xVal][current.yVal].touched = true;
	
	int i = 0;
	int j = 0;
	int min_moves = 10;		// the max for any move is really six
	int min_i = -1;
	int min_j = -1;
	while (i < COLUMNS)
	{
		while (j < ROWS)
		{
			if (board[i][j].num_of_moves < min_moves && 
				board[i][j].touched == false)
			{
				min_i = i;
				min_j = j;
				min_moves = board[i][j].num_of_moves
				
				if (min_moves == 1)
				{	// to exit while loops
					i = COLUMNS;
					j = ROWS
				}
			}
		}
	}
	
	// if either min_i or min_j < 0 then you are done
	if (min_i < 0) 
	{
		return Hash(current.xVal, current.yVal);
	}
	else 
	{	total_moves = total_moves + min_moves;
		return Hash(min_i, min_j);
	}

	
	
	
	
}
*/


void InitTouched(bool touched[COLUMNS][ROWS])
{
	for (int i = 0; i < COLUMNS; i = i + 1)
	{
		for (int j = 0; j < ROWS; j = j + 1)
		{
			touched[i][j] = false;
		}
	}
}


int Hash(int i, int j)
{	
	
	// Levels 0-7 are i = 0
	// Levels 8-15 are i = 1
	// etc...
	 
	
	return ((4*i) + j);
}

/*
void ReverseHash(int num, int &xVal, int &yVal)
{
	xVal = num/8;
	yVal = num%8;
}


 //num%8 = j
 //num/8 = i


*/


