/*
 *  queue.cpp
 *  
 *
 *  Created by Max Corman on 1/19/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

//#include "queue.h"
#include <cstdlib>

using namespace std;

class ArrayQueueFull {};
class ArrayQueueEmpty {};

template <typename T>
class ArrayQueue
{ public:
	ArrayQueue(int len);
	~ArrayQueue();
	bool empty();
	bool full();
	void enqueue(T elt);
	T dequeue();
	
private:
	T *m_arr;
	int m_left;	//location to dequeue from
	int m_right; //location to enqueue from
	int m_max_size; // maximum size as supplied by the constructor
	int m_cur_size; // current number of elements inside the container
	ArrayQueue(); // default constructor illegal
};


// constructor
template <typename T>
ArrayQueue<T>::ArrayQueue(int len)
{
	m_arr = new T[len];
	m_max_size = len;
	m_cur_size = 0;
	m_left = 0;
	m_right = 0;
	//for (int i = 0; i < len; i = i + 1)
	//{
	//	m_arr[i] = 0;
	//}
}

// deconstructor
template <typename T>
ArrayQueue<T>::~ArrayQueue()
{
	delete [] m_arr;
	m_arr = NULL;	// so that way m_arr doesn't just point to something random
}

// bool empty
template <typename T>
bool ArrayQueue<T>::empty()
{
	if (m_cur_size == 0)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

// bool full
template <typename T>
bool ArrayQueue<T>::full()
{
	if (m_cur_size == m_max_size)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

// enqueue.  add ints to the bottom
template <typename T>
void ArrayQueue<T>::enqueue(T elt)
{
	// check to see if array is full
	if (full() == true)
	{	
		ArrayQueueFull aFull;
		throw aFull;
	}
	
	if (empty() == true) 
	{
		m_arr[m_left] = elt;
	}
	else 
	{
		m_arr[m_right] = elt;
	}
	
	//m_arr[m_right] = elt;
	m_right = m_right + 1;
	if (m_right == m_max_size)
	{
		m_right = 0;
	}
	m_cur_size = m_cur_size + 1;
}

// dequeue. takes off from the top
template <typename T>
T ArrayQueue<T>::dequeue()
{
	// check to see if array is empty
	if (empty() == true)
	{	
		ArrayQueueEmpty aEmpty;
		throw aEmpty;
	}
	
	T dQ = m_arr[m_left];
	
	//for (int i = m_left; i < m_cur_size; i = i + 1)
	//{
	//	m_arr[i] = m_arr[i + 1];
	//}
	m_left = m_left + 1;
	if (m_left == m_max_size)
	{
		m_left = 0;
	}
	
	m_cur_size = m_cur_size - 1;
	return dQ;
}

// default constructor. illegal
template <typename T>
ArrayQueue<T>::ArrayQueue()
{
	// Woooopeeee!!!
}

// how to expand the array. if the array is full
// you need to make a new one, copy the elements
// then 
/*
 if (full() == true)
 {
 int *newArray = new int[m_max_size + 1];
 for (int i = 0; i < m_max_size + 1; i = i + 1)
 {
 newArray[i] = m_arr[i];
 }
 
 m_max_size = m_max_size + 1;
 delete m_arr;
 m_arr = newArray;
 }
 
 */




