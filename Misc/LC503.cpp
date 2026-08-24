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

vector<int> nextGreaterElements(vector<int> &nums)
{
    vector<int> ans(nums.size(), -1);
    stack<int> stk;

    for (int i = 0; i < 2 * nums.size() - 1; i++)
    {
        int idx = i % nums.size();

        while (!stk.empty() && nums[idx] > nums[stk.top()])
        {
            int previous = stk.top();
            stk.pop();

            ans[previous] = nums[idx];
        }

        if (i < nums.size())
        {
            stk.push(idx);
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 1};

    vector<int> ans = nextGreaterElements(nums);

    for (int x : ans)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}