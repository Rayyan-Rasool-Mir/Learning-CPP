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

bool dfs(vector<vector<int>> &grid, int r, int c)
{
    if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size())
    {
        return false;
    }

    if (grid[r][c] == 1)
    {
        return true;
    }

    grid[r][c] = 1;

    bool up = dfs(grid, r - 1, c);
    bool down = dfs(grid, r + 1, c);
    bool left = dfs(grid, r, c - 1);
    bool right = dfs(grid, r, c + 1);

    return up && down && left && right;
}

int closedIsland(vector<vector<int>> &grid)
{
    int row = grid.size();
    int col = grid[0].size();

    int count = 0;

    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++)
        {
            if (grid[r][c] == 0)
            {
                bool isClosed = dfs(grid, r, c);
                if (isClosed)
                {
                    count++;
                }
            }
        }
    }

    return count;
}

int main()
{
    vector<vector<int>> grid = {
        {1, 1, 1, 1, 0, 1, 1, 1},
        {1, 0, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 1, 0, 1, 1, 1},
        {1, 0, 0, 0, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1}
    };
    int result = closedIsland(grid);
    cout << "Number of closed islands: " << result << endl;
    return 0;
}