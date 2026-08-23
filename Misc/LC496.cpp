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

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    stack<int> stk;
    vector<int> ans(nums1.size(), -1);
    vector<int> next(nums2.size(), -1);

    for (int i = 0; i < nums2.size(); i++)
    {
        while (!stk.empty() && nums2[i] > nums2[stk.top()])
        {
            int prev = stk.top();

            stk.pop();

            next[prev] = nums2[i];
        }
        stk.push(i);
    }

    for (int i = 0; i < nums1.size(); i++)
    {
        for (int j = 0; j < nums2.size(); j++)
        {
            if (nums1[i] == nums2[j])
            {
                ans[i] = next[j];
                break;
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> ans = nextGreaterElement(nums1, nums2);

    for (int x : ans)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}