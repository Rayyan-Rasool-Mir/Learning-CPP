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

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int total = 0;
    int tank = 0;
    int ans = 0;

    for (int i = 0; i < gas.size(); i++)
    {
        int gain = gas[i] - cost[i];

        total += gain;
        tank += gain;

        if (tank < 0)
        {
            ans = i + 1;
            tank = 0;
        }
    }

    if (total < 0)
    {
        return -1;
    }

    return ans;
}

int main()
{
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};

    cout << canCompleteCircuit(gas, cost) << endl;

    return 0;
}