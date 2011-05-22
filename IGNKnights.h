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
	
};	

const int ROWS = 8;
const int COLUMNS = 8;
const int NOT_VISITED = -1;

void Initialize(spot **board);
void Djikstra(spot current, spot **board);
void Print(spot **board);

void Djikstra(spot current, spot **board)
{	// when called, current is the start location on the board 
	// because each "edge" is this graph is 1, when you enqueue 
	// it, it is going to be the fastest way to get there, therefore
	// you do not see to search for the smallest value. It will
	// always be your next one.
	
	/* 
	 
	 board looks like this
	 
	  01234567
	0 ........
	1 ........
	2 ........ 
	3 ........ 
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
	for (int i = 0; i < ROWS; i = i + 1)
	{
		for (int j = 0; j < COLUMNS; j = j + 1)
		{
			board[i][j].xVal = i;
			board[i][j].yVal = j;
			board[i][j].num_of_moves = NOT_VISITED;
			// -1 means the spot has not been visited yet
		}
	}
}

void Print(spot **board)
{
	for (int i = 0; i < ROWS; i = i + 1)
	{
		for (int j = 0; j < COLUMNS; j = j + 1)
		{
			cout << board[i][j].num_of_moves << " ";
		}
		cout << endl;
	}
}



