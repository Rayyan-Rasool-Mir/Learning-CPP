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

void backtrack(vector<int> &nums, int idx, vector<vector<int>> &ans)
{
    if (idx == nums.size())
    {
        ans.push_back({nums});
        return;
    }

    for (int i = idx; i < nums.size(); i++)
    {
        swap(nums[idx], nums[i]);
        backtrack(nums, idx + 1, ans);

        swap(nums[idx], nums[i]);
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    backtrack(nums, 0, ans);
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> ans = permute(nums);

    for (vector<int> permutation : ans)
    {
        for (int x : permutation)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}