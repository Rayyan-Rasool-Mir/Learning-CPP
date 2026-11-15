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

int minimumSumSubarray(vector<int> &nums, int l, int r)
{
    int ans = INT_MAX;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        int sum = 0;

        for (int j = i; j < n && j < i + r; j++)
        {
            sum += nums[j];

            int len = j - i + 1;

            if (len >= l && sum > 0)
            {
                ans = min(ans, sum);
            }
        }
    }
    if (ans == INT_MAX)
    {
        return -1;
    }
    return ans;
}

int main()
{
    vector<int> nums1 = {1, -2, 3, 4, -5, 6};
    int l1 = 2;
    int r1 = 4;
    int result1 = minimumSumSubarray(nums1, l1, r1);
    cout << "Minimum sum of subarray with length between " << l1 << " and " << r1 << ": " << result1 << endl;

    vector<int> nums2 = {-2, 2, -3, 1};
    int l2 = 2;
    int r2 = 3;
    int result2 = minimumSumSubarray(nums2, l2, r2);
    cout << "Minimum sum of subarray with length between " << l2 << " and " << r2 << ": " << result2 << endl;
    return 0;
}