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

vector<string> createGrid(int m, int n)
{
    vector<string> grid(m, string(n, '#'));

    for (int i = 0; i < n; i++)
    {
        grid[0][i] = '.';
    }

    for (int i = 1; i < m; i++)
    {
        grid[i][n - 1] = '.';
    }

    return grid;
}

int main()
{
    int m = 3, n = 4;
    vector<string> grid = createGrid(m, n);
    for (const auto& row : grid)
    {
        cout << row << endl;
    }
    return 0;
}