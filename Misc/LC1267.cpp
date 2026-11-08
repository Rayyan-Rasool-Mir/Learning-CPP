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

int countServers(vector<vector<int>> &grid)
{
    vector<int> rowCount(grid.size());
    vector<int> colCount(grid[0].size());

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 1)
            {
                rowCount[i]++;
                colCount[j]++;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 1)
            {
                if (rowCount[i] > 1 || colCount[j] > 1)
                {
                    ans++;
                }
            }
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> grid = {{1,1,0,0},{0,0,1,0},{0,0,1,0},{0,0,0,1}};
    int result = countServers(grid);
    cout << "Number of servers that can communicate: " << result << endl;
    return 0;
}