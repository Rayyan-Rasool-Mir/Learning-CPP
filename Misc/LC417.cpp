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

vector<vector<int>> bfs(vector<vector<int>> &heights, int type)
{
    int n = heights.size();
    int m = heights[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));

    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (type == 0 && (i == 0 || j == 0))
            {
                q.push({i, j});
                vis[i][j] = 1;
            }
            if (type == 1 && (i == n - 1 || j == m - 1))
            {
                q.push({i, j});
                vis[i][j] = 1;
            }
        }
    }

    // for bfs neighbour checking
    int row_coords[] = {-1, 0, 1, 0};
    int col_coords[] = {0, 1, 0, -1};

    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int new_row = row + row_coords[i];
            int new_col = col + col_coords[i];

            if (new_row >= 0 && new_col >= 0 && new_row <= n - 1 && new_col <= m - 1 && !vis[new_row][new_col] && heights[new_row][new_col] >= heights[row][col])
            {
                vis[new_row][new_col] = 1;
                q.push({new_row, new_col});
            }
        }
    }

    return vis;
}

vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
{
    int n = heights.size();
    int m = heights[0].size();
    vector<vector<int>> ans;

    vector<vector<int>> vis1 = bfs(heights, 0);
    vector<vector<int>> vis2 = bfs(heights, 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis1[i][j] == 1 && vis2[i][j] == 1)
            {
                ans.push_back({i, j});
            }
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> heights1 = {
        {1, 2, 2, 3, 5},
        {3, 2, 3, 4, 4},
        {2, 4, 5, 3, 1},
        {6, 7, 1, 4, 5},
        {5, 1, 1, 2, 4}};

    vector<vector<int>> heights2 = {
        {1}};

    vector<vector<int>> heights3 = {
        {1, 2},
        {3, 4}};

    vector<vector<int>> ans1 = pacificAtlantic(heights1);
    vector<vector<int>> ans2 = pacificAtlantic(heights2);
    vector<vector<int>> ans3 = pacificAtlantic(heights3);

    cout << "Test 1:" << endl;
    for (auto cell : ans1)
        cout << "[" << cell[0] << ", " << cell[1] << "] ";
    cout << endl;

    cout << "Test 2:" << endl;
    for (auto cell : ans2)
        cout << "[" << cell[0] << ", " << cell[1] << "] ";
    cout << endl;

    cout << "Test 3:" << endl;
    for (auto cell : ans3)
        cout << "[" << cell[0] << ", " << cell[1] << "] ";
    cout << endl;

    return 0;
}