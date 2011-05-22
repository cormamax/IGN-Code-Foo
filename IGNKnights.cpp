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
 
 
*/



#include "IGNKnights.h"

using namespace std;

int main(void)
{
	
	
	// declare chess board
	spot **board;
	board = new spot *[ROWS];
	for (int i = 0; i < ROWS; i = i + 1)
	{
		board[i] = new spot[COLUMNS];
	}

	// declare start and end spots
	spot start;
	start.xVal = 0;
	start.yVal = 0;
	
	spot end;
	end.xVal = 0;
	end.yVal = 0;
	
		
	
	// use Djikstra's to find minimum number of moves
	// check the psuedo code of it
	// do you need a stack/queue to hold on to the info
	// of which one has the least moves so you can
	// check it next? Insert into an array based queue
	// and when you insert, insert it in order?
	
	Djikstra(start, board);
	
	Print(board);
	
	
	
	
	
	
	return 0;
	
}










