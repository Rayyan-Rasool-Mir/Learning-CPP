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

long long countNonDecreasingSubarrays(vector<int> &nums, int k)
{
    int ans = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        int m = nums[i];

        int cost = 0;
        for (int j = i; j < nums.size(); j++)
        {
            m = max(m, nums[j]);
            cost += m - nums[j];

            if (cost <= k)
            {
                ans++;
            }
            else
            {
                break;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {3, 1, 2, 1};
    int k = 5;
    long long result = countNonDecreasingSubarrays(nums, k);
    cout << "Number of non-decreasing subarrays: " << result << endl;
    return 0;
}