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

int minCostClimbingStairs(vector<int> &cost)
{
    int prev1 = 0;
    int prev2 = 0;

    for (int i = 2; i <= cost.size(); i++)
    {
        int current = min(prev1 + cost[i - 1], prev2 + cost[i - 2]);

        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
}

int main()
{
    vector<int> cost = {10, 15, 20};
    cout << minCostClimbingStairs(cost) << endl; // Output: 15
    return 0;
}