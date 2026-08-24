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

void include(int idx, vector<int> &nums, vector<int> &current, vector<vector<int>> &ans)
{
    if (idx == nums.size())
    {
        ans.push_back(current);
        return;
    }

    include(idx + 1, nums, current, ans);

    current.push_back(nums[idx]);
    include(idx + 1, nums, current, ans);
    current.pop_back();
}
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> current;

    include(0, nums, current, ans);
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> ans = subsets(nums);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << "{ ";

        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }

        cout << "}" << endl;
    }

    return 0;
}