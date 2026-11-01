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

int uniquePaths(vector<vector<int>> &grid)
{
    long long mod = 1e9 + 7;
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = 1;

    for (int sum = 0; sum < m + n - 1; sum++)
    {
        for (int i = 0; i < m; i++)
        {
            int j = sum - i;

            if (j < 0 || j >= n)
            {
                continue;
            }

            if (grid[i][j] == 1 || dp[i][j] == 0)
            {
                continue;
            }

            int r = i;
            int c = j + 1;

            bool enteredFromRight = true;

            while (r < m && c < n && grid[r][c] == 1)
            {
                if (enteredFromRight)
                    r++;
                else
                    c++;

                enteredFromRight = !enteredFromRight;
            }

            if (r < m && c < n)
            {
                dp[r][c] += dp[i][j];
                dp[r][c] %= mod;
            }

            r = i + 1;
            c = j;

            enteredFromRight = false;

            while (r < m && c < n && grid[r][c] == 1)
            {
                if (enteredFromRight)
                    r++;
                else
                    c++;

                enteredFromRight = !enteredFromRight;
            }

            if (r < m && c < n)
            {
                dp[r][c] += dp[i][j];
                dp[r][c] %= mod;
            }
        }
    }

    return dp[m - 1][n - 1];
}

int main()
{
    vector<vector<int>> grid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}};
    cout << "Unique paths from (0,0) to (" << grid.size() - 1 << "," << grid[0].size() - 1 << ") is: " << uniquePaths(grid) << endl;
    return 0;
}