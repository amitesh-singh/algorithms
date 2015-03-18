#include <iostream>
#include <vector>
#include <cmath>

//plane sweep algo
// bruteforce approach O(n^2)

struct Point
{
   int x, y;
 public:
   Point():x(0), y(0) {}
   Point(int _x, int _y):x(_x), y(_y) {}

   bool operator != (Point &rhs)
     {
        if (x != rhs.x && y != rhs.y)
          return true;
        else
          return false;
     }

   double distance(Point &p)
     {
        double d;
        d = sqrt((x - p.x)*(x - p.x) + (y - p.y)*(y - p.y));

        return d;
     }

   void print()
     {
        std::cout << "x: " << x;
        std::cout << ", y: " << y << std::endl;
     }
};

//brute force algos.
// Complexity O(n^2);
//I know i can do better!! :)
Point *findNaiveClosestPair(std::vector<Point> &points)
{
   double min = 10000000.00; // whats the big double value.. need to revise C++
   Point *closestpair = new Point[2];

   for (int i = 0; i < points.size(); ++i)
     {
        for (int j = 0; j < points.size(); ++j)
          {
             if (points[i] != points[j])
               {
                  double dist = points[i].distance(points[j]);

                  if (dist < min)
                    {
                       min = dist;
                       closestpair[0] = points[i];
                       closestpair[1] = points[j];
                    }
               }
          }
     }

   return closestpair;
}

int main(int argc, char **argv)
{
   Point p1(20, 20), p2(40, 43);

   std::cout << "distance: " << p1.distance(p2) << std::endl;

   std::vector<Point> points;

   points.push_back(p1);
   points.push_back(p2);
   points.push_back(Point(100, 200));

   //Randomize the output:-> TODO
   for (int i = 0; i < 10; ++i)
     {
        points.push_back(Point(100 + i, 200 + i));
     }

   Point *closestpair = findNaiveClosestPair(points);
   for (int i = 0; i < 2; ++i)
     {
        closestpair[i].print();
     }

   delete[] closestpair;

   return 0;
}
