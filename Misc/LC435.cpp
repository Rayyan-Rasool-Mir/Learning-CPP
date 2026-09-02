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

static bool comp(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}
int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end(), comp);
    int previous = 0;
    int count = 1;

    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] >= intervals[previous][1])
        {
            previous = i;
            count++;
        }
    }

    return intervals.size() - count;
}

int main()
{
    vector<vector<int>> intervals = {
        {1, 2},
        {2, 3},
        {3, 4},
        {1, 3}
    };

    cout << eraseOverlapIntervals(intervals) << endl;

    return 0;
}