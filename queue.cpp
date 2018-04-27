#include <iostream>
#include <cctype>
#include <fstream>
#include "queue.h"
using namespace std;

	queue::queue() //constructor
	{
		front = 0;
		rear = CAPACITY - 1;
		count = 0;
	}

	void queue::enqueue(const Item& entry) //append value to the rear end of queue
	{
		rear = next_index(rear);
		data[rear] = entry;
		++count;
	}

	queue::Item queue::dequeue() //remove value from front end of queue
	{
		Item dequeued;
		dequeued = data[front];
		front = next_index(front);
		--count;
		return dequeued;
	}

	ostream& operator << (ostream& out_s, queue& q) //print all values of the queue
	{
		int dequeued, i;
		int n = q.size();

		for( i = 0; i < n; ++i )
		{
			dequeued = q.dequeue();
			out_s << dequeued << " ";
			q.enqueue(dequeued);
		}
		return out_s;
	}
