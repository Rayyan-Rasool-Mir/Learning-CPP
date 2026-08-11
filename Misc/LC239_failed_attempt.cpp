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

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> ans;
    for (int i = 0; i <= nums.size() - k; i++)
    {
        int maxi = nums[i];

        for (int j = i; j < i + k; j++)
        {
            maxi = max(maxi, nums[j]);
        }

        ans.push_back(maxi);
    }

    return ans;
}
int main()
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> ans = maxSlidingWindow(nums, k);

    for(int x : ans)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}