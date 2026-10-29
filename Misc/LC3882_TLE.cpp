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


int dfs(vector<vector<int>> &grid, int i, int j, int curXOR)
{
    curXOR ^= grid[i][j];
    
    if (i == grid.size() - 1 && j == grid[0].size() - 1)
    {
        return curXOR;
    }
    
    int ans = INT_MAX;
    
    if (j + 1 < grid[0].size())
    {
        ans = min(ans, dfs(grid, i, j + 1, curXOR));
    }
    
    if (i + 1 < grid.size())
    {
        ans = min(ans, dfs(grid, i + 1, j, curXOR));
    }
    
    return ans;
}

int minCost(vector<vector<int>> &grid)
{
    return dfs(grid, 0, 0, 0);
}

int main()
{
    vector<vector<int>> grid = {{0, 1}, {1, 0}};
    cout << minCost(grid) << endl;
    return 0;
}