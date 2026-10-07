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

int maxSubArray(vector<int> &nums)
{
    int current = nums[0];
    int best = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        current = max(nums[i], current + nums[i]);
        best = max(current, best);
    }

    return best;
}

int main()
{
    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> nums2 = {1};
    vector<int> nums3 = {5, 4, -1, 7, 8};
    vector<int> nums4 = {-1, -2, -3, -4};
    vector<int> nums5 = {-2, 1};

    cout << "Test 1: " << maxSubArray(nums1) << endl; // 6
    cout << "Test 2: " << maxSubArray(nums2) << endl; // 1
    cout << "Test 3: " << maxSubArray(nums3) << endl; // 23
    cout << "Test 4: " << maxSubArray(nums4) << endl; // -1
    cout << "Test 5: " << maxSubArray(nums5) << endl; // 1

    return 0;
}