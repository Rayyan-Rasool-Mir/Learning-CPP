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

int findKthLargest(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    return nums[nums.size() - k];
}

int main()
{
    vector<int> nums1 = {3, 2, 1, 5, 6, 4};
    vector<int> nums2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};

    cout << "Test 1: " << findKthLargest(nums1, 2) << endl; // 5
    cout << "Test 2: " << findKthLargest(nums2, 4) << endl; // 4

    return 0;
}