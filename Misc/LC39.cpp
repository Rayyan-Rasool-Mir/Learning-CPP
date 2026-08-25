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

void backtrack(int idx, int remaining, vector<vector<int>> &ans, vector<int> &current, vector<int> &candidates)
{
    if (remaining == 0)
    {
        ans.push_back(current);
        return;
    }
    if (idx == candidates.size())
    {
        return;
    }

    if (candidates[idx] <= remaining)
    {
        current.push_back(candidates[idx]);
        backtrack(
            idx,
            remaining - candidates[idx],
            ans,
            current,
            candidates);

        current.pop_back();
    }

    backtrack(
        idx + 1,
        remaining,
        ans,
        current,
        candidates);
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> current;

    backtrack(0, target, ans, current, candidates);

    return ans;
}

int main()
{
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> ans = combinationSum(candidates, target);

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