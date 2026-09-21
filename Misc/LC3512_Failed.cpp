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

vector<long long> resultArray(vector<int> &nums, int k)
{
    vector<long long> ans(k, 0);

    for (int i = 0; i < nums.size(); i++)
    {
        long long prod = 1;

        for (int j = i; j < nums.size(); j++)
        {
            prod *= nums[j];
            long long remainder = prod % k;
            ans[remainder]++;
        }
    }

    return ans;
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