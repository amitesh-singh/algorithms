/*
   One day’s data set is available in file lot.txt on First Class.

   Arrival/Departure Code: char (A or D) License string (ex. BOSS) Time integer value representing military time

 A EARLYBIRD 630
 A WORKER 700 
 A CEO 730
 A CLERK 730
 A MANAGER 800
 A VP 900
 D CLERK 930
 A SHOPPER 1000
 D CEO 1000
 D EARLYBIRD 1030
 D WORKER 1100
 A JANITOR 1100
 D MANAGER 1130

   A vehicle should be recorded as a struct containing the license and the arrival time. For simplicity, time will be an integer representing military time. Include the C++ string class.
   struct Vehicle { string license; // license value
   int arrival; // arrival in military time ( 0 – 2359) };

   Read in the lines of the data files and recreate the movement of cars in and out of the parking lot. Vehicles are charged $8.00 per hour for the duration of their stay. Partial hours are rounded up. You can assume that only owners of cars in the lot arrive with a departure request. Report any cars left in the lot at day end as well as the sum of charges. Use the template stack and queue classes discussed in lecture.

   For each arrival processed you should report: Car with license xxxxxx parked at xxxx or Car with license xxxxxx was turned away at xxxx – LOT IS FULL!

   For each departure processed you should report: Car with license xxxxxx left at xxxx paying $xx.xx
*/
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>

using namespace std;

int testCases = 0;
struct Vehicle{
     char ad; //arrival or departure, A or D
     string license;
     string time;

     void print()
       {
          cout << ad << " " << license << " " << time << endl;
       }
};

int main()
{
   freopen("car_lists.txt", "r", stdin);
   cin >> testCases;
   cout << "test cases: " << testCases << endl;

   stack<Vehicle> carStack;
   queue<Vehicle> q;
   for (int test_case = 1; test_case <= testCases; ++test_case)
     {
        Vehicle v;
        cin >> v.ad;
        cin >> v.license;
        cin >> v.time;
   //     v.print();

        if (v.ad == 'A')
          {
             cout << "Car (" << v.ad << "," << v.license << ")" << " arrived at " << v.time << ".\n";
             carStack.push(v);
          }
        else
          {
             cout << "Car (" << v.ad << "," << v.license << ")" << " departed at " << v.time << ".\n";
             //find the car and delete it.
             while(!carStack.empty())
               {
                  if (carStack.top().license == v.license)
                    {
                       carStack.pop();
                       break;
                    }
                  else
                    {
                       q.push(carStack.top());
                       carStack.pop();
                    }
               }
             //copy queue back to stack.
             while(!q.empty())
               {
                  carStack.push(q.front());
                  q.pop();
               }
          }
     }

   //lets print remaining stack
   cout << "\nCar Parking Status: \n";
   if (carStack.empty())
     {
        cout << "Hurray, Parking is free\n";
     }
   else
     while (!carStack.empty())
       {
          carStack.top().print();
          carStack.pop();
       }

   return 0;
}
