#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include "circle.h"
using namespace std;
int main()
{
    srand(time(0));
    vector<Circle> circles;
    for (int i = 0; i < 10; ++i)
    {
        circles.push_back(Circle(rand() % 100,
                                 rand() % 100,
                                 rand() % 103 + 3));
    }

    cout << "Max touches: " << endl;
    int maxTouches = 0;
    int index = 0;
    int touches;
    for(int i = 0; i < circles.size(); ++i)
    {
        touches = 0;
        for(int j = 0; j < circles.size(); ++j)
        {
            if (intersections(circles[i], circles[j]) == 1)
            {
                ++touches;
            }
        }
        if(touches > maxTouches)
        {
            maxTouches = touches;
            index = i;
        }
    }
    cout << circles[index] << endl;

    cout << "Enter a number" << endl;
    double n;
    cin >> n;
    for(int i = 0; i < circles.size(); ++i)
    {
        if(circles[i].area() > n)
        {
            cout << circles[i] << endl;
        }
    }


    return 0;
}
