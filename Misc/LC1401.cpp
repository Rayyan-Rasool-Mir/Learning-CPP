#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <numeric>
#include <cmath>
#include <climits>
using namespace std;

bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2)
{
    int closestX = max(x1, min(xCenter, x2));
    int closestY = max(y1, min(yCenter, y2));

    int dist = ((xCenter - closestX) * (xCenter - closestX)) + (yCenter - closestY) * (yCenter - closestY);

    if (radius * radius >= dist)
    {
        return true;
    }

    return false;
}

int main()
{
    cout << boolalpha;

    cout << checkOverlap(1, 0, 0, 1, -1, 3, 1) << endl; // true
    cout << checkOverlap(1, 0, 0, 2, 2, 3, 3) << endl;  // false
    cout << checkOverlap(1, 0, 0, -1, -1, 1, 1) << endl; // true
    cout << checkOverlap(2, 5, 5, 0, 0, 3, 3) << endl;  // false

    return 0;
}