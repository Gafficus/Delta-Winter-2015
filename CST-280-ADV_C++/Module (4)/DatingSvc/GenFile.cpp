#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <iostream>
using namespace std;
int main()
{
	clock_t timer;
	timer = clock();				// Set seed for random number 
	srand(timer);					//  to current clock time
	int x,app,i,newID;

	ofstream datelist("clientDB.txt");
	
	
	bool used[32767];
	for (int i=0; i < 32767; i++)
	   used[i] = false;

	for (app=1;app <=200;app++)
	{	
	
	     newID = rand();
	     while (newID < 10000 || used[newID])
	     {
	       	     newID = rand();  
	     }
	     used[newID] = true;
			    
	     datelist << newID ;



		for (i=0;i<26;i++)
		{
			x = rand() % 3;
			if (x == 1)
			{
			    datelist << ',' ;

				datelist << char(65 + i);
//				cout << char(65 + i) <<  endl;
			}
		}	
			datelist << std::endl;
	}
	system("pause");
	return 0;
}

