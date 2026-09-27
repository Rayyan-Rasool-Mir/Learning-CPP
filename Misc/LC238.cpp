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

vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n);
    vector<int> prefix(n);
    vector<int> suffix(n);

    prefix[0] = 1;

    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] * nums[i - 1];
    }

    suffix[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        suffix[i] = suffix[i + 1] * nums[i + 1];
    }

    for (int i = 0; i < n; i++)
    {
        ans[i] = prefix[i] * suffix[i];
    }

    return ans;
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 4};

    vector<int> ans1 = productExceptSelf(nums1);

    cout << "Test 1: ";
    for (int x : ans1)
        cout << x << " ";
    cout << endl;

    return 0;
}