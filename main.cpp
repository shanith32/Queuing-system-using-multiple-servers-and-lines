#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "queue.h"

using namespace std;


int main()
{
  int trans_time = 0;
  int count = 0;
  int wait_sum = 0;
  int wide = 0;
  int seed ,entry_time, twos, ARV_PROB, MAX_TRANS_TIME, DURATION;
  queue q;


  cout << "Please enter the following values for the simulation,"<< endl;

  cout << "The number of lines/servers,"<< endl;
  cin >> twos;

  cout << "The probability a customer arrives in one tickmark," << endl;
  cin >> ARV_PROB;

  cout << "The maximum duration of a transaction," << endl;
  cin >> MAX_TRANS_TIME;

  cout << "The duration of the simulation," << endl;
  cin >> DURATION;

  cout << "Random number to seed," << endl;
  cin >> seed;
  srand(seed);

  for ( int t = 0; t < DURATION; ++t )
  {

  	  for ( int i = 0; i < twos; ++i )
	  {

		if ( rand() % 100 < ARV_PROB )
		{
			q.enqueue(t);
		}

		else if ( trans_time == 0 )
		{
			if ( !q.empty() )
			{
				entry_time = q.dequeue();
				wait_sum += ( t - entry_time );
				++count;
				trans_time = (rand() % MAX_TRANS_TIME) + 1;

				if ( wide < t - entry_time )
				{
					wide = ( t - entry_time );
				}
			}
		}

		else
		{
			--trans_time;
		}
			cout << setw(4) << t + 1 << setw(4) << trans_time << "  " << q << endl;
			cout << endl;
	  }
  }

  cout << count << " customers waited an average of " << wait_sum / count << endl;
  cout << "The longest time a customer waited was "<< wide << endl;
  cout << q.size() << " customers left in line." << endl;

}
