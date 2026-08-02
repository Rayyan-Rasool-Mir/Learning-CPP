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

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end());

    vector<int> current = intervals[0];
    for (int i = 1; i < intervals.size(); i++)
    {
        vector<int> next;
        next = intervals[i];
        if (current[1] >= next[0])
        {
            current[1] = max(current[1], intervals[i][1]);
        }
        else
        {
            ans.push_back(current);
            current = intervals[i];
        }
    }
    ans.push_back(current);

    return ans;
}

int main()
{
    vector<vector<int>> intervals = {
        {1,3},
        {2,6},
        {8,10},
        {15,18}
    };

    vector<vector<int>> ans = merge(intervals);

    for(auto &interval : ans)
    {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }

    return 0;
}