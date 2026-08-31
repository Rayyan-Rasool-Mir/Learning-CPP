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

int findMinArrowShots(vector<vector<int>> &points)
{
    sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b)
         { return a[1] < b[1]; });

    int arrow = 1;
    int arrowpos = points[0][1];

    for (int i = 1; i < points.size(); i++)
    {
        if (points[i][0] > arrowpos)
        {
            arrow++;
            arrowpos = points[i][1];
        }
    }

    return arrow;
}

int main()
{
    vector<vector<int>> points = {
        {10, 16},
        {2, 8},
        {1, 6},
        {7, 12}
    };

    cout << findMinArrowShots(points) << endl;

    return 0;
}