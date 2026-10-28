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

long long dfs(vector<vector<int>> &grid, int i, int j)
{
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
    {
        return 0;
    }

    if (grid[i][j] <= 0)
    {
        return 0;
    }

    long long value = grid[i][j];
    grid[i][j] = 0;

    value += dfs(grid, i - 1, j);
    value += dfs(grid, i + 1, j);
    value += dfs(grid, i, j - 1);
    value += dfs(grid, i, j + 1);

    return value;
}
int countIslands(vector<vector<int>> &grid, int k)
{
    int row = grid.size();
    int col = grid[0].size();
    int count = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] > 0)
            {
                long long sum = dfs(grid, i, j);

                if (sum % k == 0)
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
    vector<vector<int>> grid = {{0,2,1,0,0},{0,5,0,0,5},{0,0,1,0,0},{0,1,4,7,0},{0,2,0,0,8}};
    int k = 5;
    int result = countIslands(grid, k);
    cout << "The number of islands with sum divisible by " << k << " is: " << result << endl;
    return 0;
}