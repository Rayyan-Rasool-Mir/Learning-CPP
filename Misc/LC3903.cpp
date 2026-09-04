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
    vector<int> prefix(nums.size());
    vector<int> suffix(nums.size());
    prefix[0] = nums[0];
    suffix[nums.size() - 1] = nums[nums.size() - 1];

    for (int i = 1; i < nums.size(); i++)
    {
        prefix[i] = max(prefix[i - 1], nums[i]);
    }

    for (int i = nums.size() - 2; i >= 0; i--)
    {
        suffix[i] = min(suffix[i + 1], nums[i]);
    }

    for (int i = 0; i < nums.size(); i++)
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