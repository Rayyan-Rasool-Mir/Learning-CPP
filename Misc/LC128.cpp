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

int longestConsecutive(vector<int> &nums)
{
    unordered_set<int> s;

    for (int i = 0; i < nums.size(); i++)
    {
        s.insert(nums[i]);
    }

    int l = 0;

    for (int i : s)
    {
        if (!s.count(i - 1))
        {
            int current = i;
            int len = 1;

            while (s.count(current + 1))
            {
                current++;
                len++;
            }

            l = max(l, len);
        }
    }
    return l;
}

int main()
{
    vector<int> nums1 = {100, 4, 200, 1, 3, 2};
    vector<int> nums2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    vector<int> nums3 = {};
    vector<int> nums4 = {1};
    vector<int> nums5 = {1, 2, 0, 1};
    vector<int> nums6 = {9, 1, 4, 7, 3, 2, 6, 8, 5};

    cout << "Test 1: " << longestConsecutive(nums1) << endl; // 4
    cout << "Test 2: " << longestConsecutive(nums2) << endl; // 9
    cout << "Test 3: " << longestConsecutive(nums3) << endl; // 0
    cout << "Test 4: " << longestConsecutive(nums4) << endl; // 1
    cout << "Test 5: " << longestConsecutive(nums5) << endl; // 3
    cout << "Test 6: " << longestConsecutive(nums6) << endl; // 9

    return 0;
}