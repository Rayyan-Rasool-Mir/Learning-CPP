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

long long maxAlternatingSum(vector<int> &arr)
{
    vector<long long> nums;
    for (int i = 0; i < arr.size(); i++)
    {
        nums.push_back(1ll * arr[i] * arr[i]);
    }

    sort(nums.begin(), nums.end());
    long long ans = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (i < nums.size() / 2)
        {
            ans -= nums[i];
        }
        else
        {
            ans += nums[i];
        }
    }

    return ans;
}

int main()
{
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {1, -1, 2, -2, 3, -3};
    vector<int> nums3 = {5};
    vector<int> nums4 = {1, 2, 3, 4};

    cout << maxAlternatingSum(nums1) << endl; // 12
    cout << maxAlternatingSum(nums2) << endl; // 16
    cout << maxAlternatingSum(nums3) << endl; // 25
    cout << maxAlternatingSum(nums4) << endl; // 20

    return 0;
}