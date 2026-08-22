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

vector<int> dailyTemperatures(vector<int> &temperatures)
{
    vector<int> ans(temperatures.size(), 0);
    stack<int> stk;

    for (int i = 0; i < temperatures.size(); i++)
    {
        while (!stk.empty() && temperatures[i] > temperatures[stk.top()])
        {
            int previous = stk.top();
            stk.pop();

            ans[previous] = i - previous;
        }

        stk.push(i);
    }

    return ans;
}

int main()
{
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};

    vector<int> ans = dailyTemperatures(temperatures);

    for (int x : ans)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}