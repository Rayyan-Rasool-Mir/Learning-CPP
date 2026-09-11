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

void dfs(int i, int j, vector<vector<bool>> &vis, vector<vector<char>> &grid, int n, int m)
{
    if (i < 0 || j < 0 || j >= m || i >= n || vis[i][j] == true || grid[i][j] != '1')
    {
        return;
    }
    vis[i][j] = true;

    dfs(i - 1, j, vis, grid, n, m);
    dfs(i, j + 1, vis, grid, n, m);
    dfs(i + 1, j, vis, grid, n, m);
    dfs(i, j - 1, vis, grid, n, m);
}
int numIslands(vector<vector<char>> &grid)
{
    int islands = 0;
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<bool>> vis(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1' && !vis[i][j])
            {
                dfs(i, j, vis, grid, n, m);
                islands++;
            }
        }
    }
    return islands;
}

int main()
{
    vector<vector<char>> grid1 = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };

    vector<vector<char>> grid2 = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    vector<vector<char>> grid3 = {
        {'1','0','1'},
        {'0','1','0'},
        {'1','0','1'}
    };

    cout << numIslands(grid1) << endl; // 1
    cout << numIslands(grid2) << endl; // 3
    cout << numIslands(grid3) << endl; // 5

    return 0;
}