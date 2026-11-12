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

int longestMonotonicSubarray(vector<int> &nums)
{
    int count1 = 1;
    int count2 = 1;
    int ans = 1;

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > nums[i - 1])
        {
            count1++;
            count2 = 1;
        }
        else if (nums[i] < nums[i - 1])
        {
            count2++;
            count1 = 1;
        }
        else
        {
            count1 = 1;
            count2 = 1;
        }
        ans = max(ans, max(count1, count2));
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 2, 3, 4, 5, 1, 0};
    int result = longestMonotonicSubarray(nums);
    cout << "Length of the longest monotonic subarray: " << result << endl;
    return 0;
}