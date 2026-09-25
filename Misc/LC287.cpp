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
int findDuplicate(vector<int> &nums)
{
    int slow = nums[0];
    int fast = nums[0];

    while (true)
    {
        slow = nums[slow];
        fast = nums[nums[fast]];

        if (slow == fast)
        {
            break;
        }
    }
    slow = nums[0];

    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

int main()
{
    vector<int> nums1 = {1, 3, 4, 2, 2};
    vector<int> nums2 = {3, 1, 3, 4, 2};
    vector<int> nums3 = {1, 1};

    cout << "Test 1: " << findDuplicate(nums1) << endl; // 2
    cout << "Test 2: " << findDuplicate(nums2) << endl; // 3
    cout << "Test 3: " << findDuplicate(nums3) << endl; // 1

    return 0;
}