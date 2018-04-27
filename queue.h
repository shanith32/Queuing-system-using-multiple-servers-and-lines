//Nadika Bandara
//11/09/2017

//The following is a Queue ADT class built by using an array implementation methodology. This class also has functions
//to manipulate the queue ADT. The main program get data about a line and a server that will eventually simulate a queueing
//system. The main program uses enqueue() and dequeue() operations to insert and remove values from the queue. The main program
//creates an array of queue as line/serves and simulate a situation limited to a fixed time and finally give some important
//data out based on the current simulation.

#ifndef QUEUE_PROJECT
#define QUEUE_PROJECT

#include <iostream>
using namespace std;


class queue
{
    public:

	  typedef int Item; // The data type that can go inside the queue.

      static const int CAPACITY = 100; //capacity of the array


      queue( );//Constructor

      //Modification Members
      void enqueue ( const Item& entry );// to append a value on to the rear end of the queue
							//precondition – the new vlaue
							//should be matching the item type.
							//postcondition – the new value
							//has been appended to the rear end of the queue.
      Item dequeue ( ); //to remove the value on the front end of the queue
				//postcondition – the value on the last end of the queue has being removed

      //Constant Member Functions
      int size( ) const { return count; } //returns how many values inside the queue.
      bool empty( ) const { return count == 0; } //returns whether the queue has values availbale or not.

      // Friend Funtions
      friend std::ostream& operator << ( std::ostream& out_s, queue& q ); //print out all elements inside the queue

    private:
      //Data Members
      Item data[CAPACITY];         // queue's items
      int front;           // front index
      int rear;            // rear index
      int count;           // length of queue

      // private memeber functions
		int next_index ( int i ) const { return (i+1) % CAPACITY; }
  };

  #include "queue.cpp"

  #endif
