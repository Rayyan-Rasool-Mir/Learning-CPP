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

int calculateMinimumHP(vector<vector<int>> &dungeon)
{
    int m = dungeon.size();
    int n = dungeon[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));

    dp[m][n - 1] = 1;
    dp[m - 1][n] = 1;

    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            int newHealth = min(dp[i + 1][j], dp[i][j + 1]);
            dp[i][j] = max(1, newHealth - dungeon[i][j]);
        }
    }
    return dp[0][0];
}

int main()
{
    vector<vector<int>> dungeon = {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
    int result = calculateMinimumHP(dungeon);
    cout << "Minimum initial health required: " << result << endl;
    return 0;
}