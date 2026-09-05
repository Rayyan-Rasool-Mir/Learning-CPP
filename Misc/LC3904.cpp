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

int firstStableIndex(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> prefix(n);
    vector<int> suffix(n);

    prefix[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = max(prefix[i - 1], nums[i]);
    }

    suffix[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suffix[i] = min(suffix[i + 1], nums[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (prefix[i] - suffix[i] <= k)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    vector<int> nums = {5,0,1,4};
    int k = 3;

    cout << firstStableIndex(nums, k) << endl;

    return 0;
}