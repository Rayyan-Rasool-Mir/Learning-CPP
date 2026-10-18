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

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int val = 0;
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
        {
            val++;
        }
        else
        {
            ans.push_back(val);
            val = 0;
        }
    }
    ans.push_back(val);

    return *max_element(ans.begin(), ans.end());
}

int main()
{
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    cout << findMaxConsecutiveOnes(nums) << endl;
    return 0;
}