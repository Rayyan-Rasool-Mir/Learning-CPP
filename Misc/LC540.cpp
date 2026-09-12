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

int singleNonDuplicate(vector<int> &nums)
{
    int start = 0;
    int end = nums.size() - 1;
    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (mid % 2 == 1)
        {
            mid--;
        }

        if (nums[mid] == nums[mid + 1])
        {
            start = mid + 2;
            continue;
        }
        else
        {
            end = mid;
        }
    }
    return nums[start];
}

int main()
{
    vector<int> nums1 = {1, 1, 2, 3, 3, 4, 4};
    vector<int> nums2 = {1, 1, 2, 2, 3};
    vector<int> nums3 = {1, 2, 2, 3, 3, 4, 4};

    cout << singleNonDuplicate(nums1) << endl; // 2
    cout << singleNonDuplicate(nums2) << endl; // 3
    cout << singleNonDuplicate(nums3) << endl; // 1

    return 0;
}