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

vector<int> buildArray(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        ans[i] = nums[nums[i]];
    }
    return ans;
}

int main()
{
    vector<int> nums = {0, 2, 1, 5, 3, 4};
    vector<int> result = buildArray(nums);
    cout << "Resulting array: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}