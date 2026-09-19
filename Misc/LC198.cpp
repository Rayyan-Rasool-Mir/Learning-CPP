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

int rob(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n);
    if (n == 0)
    {
        return 0;
    }

    if (n == 1)
    {
        return nums[0];
    }
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++)
    {
        int robcurr = nums[i] + dp[i - 2];
        int skipcurr = dp[i - 1];
        dp[i] = max(robcurr, skipcurr);
    }

    return dp[n - 1];
}

int main()
{
    vector<int> nums1 = {2, 7, 9, 3, 1};
    vector<int> nums2 = {1, 2, 3, 1};
    vector<int> nums3 = {2, 1, 4, 9};
    vector<int> nums4 = {};
    vector<int> nums5 = {5};

    cout << "Test 1: " << rob(nums1) << endl; // 12
    cout << "Test 2: " << rob(nums2) << endl; // 4
    cout << "Test 3: " << rob(nums3) << endl; // 11
    cout << "Test 4: " << rob(nums4) << endl; // 0
    cout << "Test 5: " << rob(nums5) << endl; // 5

    return 0;
}