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

int minOperations(vector<int> &nums, int x)
{
    int total = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        total += nums[i];
    }

    int target = total - x;

    if (target < 0)
    {
        return -1;
    }

    if (target == 0)
    {
        return n;
    }

    int left = 0;
    int sum = 0;
    int longest = -1;

    for (int i = 0; i < n; i++)
    {
        sum += nums[i];

        while (sum > target)
        {
            sum -= nums[left];
            left++;
        }

        if (sum == target)
        {
            longest = max(longest, i - left + 1);
        }
    }

    if (longest == -1)
    {
        return -1;
    }
    return n - longest;
}

int main()
{
    vector<int> nums1 = {1, 1, 4, 2, 3};
    vector<int> nums2 = {5, 6, 7, 8, 9};
    vector<int> nums3 = {3, 2, 20, 1, 1, 3};
    vector<int> nums4 = {1, 1};
    vector<int> nums5 = {1, 2, 3};

    cout << "Test 1: " << minOperations(nums1, 5) << endl;  // 2
    cout << "Test 2: " << minOperations(nums2, 4) << endl;  // -1
    cout << "Test 3: " << minOperations(nums3, 10) << endl; // 5
    cout << "Test 4: " << minOperations(nums4, 3) << endl;  // -1
    cout << "Test 5: " << minOperations(nums5, 3) << endl;  // 1

    return 0;
}