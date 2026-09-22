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

vector<long long> count(vector<int> &nums, int k)
{
    vector<long long> ans(k, 0);
    vector<long long> dp(k, 0);

    for (long long i = 0; i < nums.size(); i++)
    {
        vector<long long> newdp(k, 0);
        long long remainder = nums[i] % k;
        newdp[remainder]++;

        for (long long j = 0; j < k; j++)
        {
            long long newremainder = (j * nums[i]) % k;
            newdp[newremainder] += dp[j];
        }

        for (long long j = 0; j < k; j++)
        {
            ans[j] += newdp[j];
        }

        dp = newdp;
    }
    return ans;
}
vector<long long> resultArray(vector<int> &nums, int k)
{
    return count(nums, k);
}

int main()
{
    vector<int> nums1 = {2, 3, 4};
    vector<int> nums2 = {1, 2, 3};
    vector<int> nums3 = {2, 2, 2};

    vector<long long> ans1 = resultArray(nums1, 5);
    vector<long long> ans2 = resultArray(nums2, 3);
    vector<long long> ans3 = resultArray(nums3, 4);

    cout << "Test 1: ";
    for (long long x : ans1)
        cout << x << " ";
    cout << endl;

    cout << "Test 2: ";
    for (long long x : ans2)
        cout << x << " ";
    cout << endl;

    cout << "Test 3: ";
    for (long long x : ans3)
        cout << x << " ";
    cout << endl;

    return 0;
}