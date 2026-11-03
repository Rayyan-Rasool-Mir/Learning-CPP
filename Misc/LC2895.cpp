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

int minProcessingTime(vector<int> &processorTime, vector<int> &tasks)
{
    sort(processorTime.begin(), processorTime.end());
    sort(tasks.begin(), tasks.end());

    int ans = 0;
    int j = tasks.size() - 1;

    for (int i = 0; i < processorTime.size(); i++)
    {
        int maxi = tasks[j];
        int time = processorTime[i] + maxi;

        ans = max(ans, time);
        j -= 4;
    }

    return ans;
}

int main()
{
    vector<int> processorTime = {10, 20};
    vector<int> tasks = {2, 3, 1, 2, 5, 8, 4, 3};
    cout << "Minimum processing time is: " << minProcessingTime(processorTime, tasks) << endl;
    return 0;
}