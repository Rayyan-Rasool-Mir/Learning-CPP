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

int sumCounts(vector<int> &nums)
{
    int ans = 0;

    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        set<int> temp;

        for (int j = i; j < n; j++)
        {
            temp.insert(nums[j]);
            int d = temp.size();

            ans += d * d;
        }
    }

    return ans;
}

int main()
{
    vector<int> nums1 = {1, 2, 3};
    cout << sumCounts(nums1) << endl; // 20

    vector<int> nums2 = {1, 1};
    cout << sumCounts(nums2) << endl; // 3

    vector<int> nums3 = {1, 2, 1};
    cout << sumCounts(nums3) << endl; // 15

    vector<int> nums4 = {1, 2, 3, 4};
    cout << sumCounts(nums4) << endl; // 50

    return 0;
}