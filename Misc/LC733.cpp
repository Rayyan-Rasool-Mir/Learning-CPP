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

void dfs(vector<vector<int>> &image, int sr, int sc, int color, int Newcolor)
{
    if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size() || image[sr][sc] != color)
    {
        return;
    }

    image[sr][sc] = Newcolor;

    dfs(image, sr - 1, sc, color, Newcolor);
    dfs(image, sr + 1, sc, color, Newcolor);
    dfs(image, sr, sc + 1, color, Newcolor);
    dfs(image, sr, sc - 1, color, Newcolor);
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int Newcolor)
{
    if (image[sr][sc] == Newcolor)
    {
        return image;
    }

    dfs(image, sr, sc, image[sr][sc], Newcolor);

    return image;
}

int main()
{
    vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    int sr = 1, sc = 1, Newcolor = 2;
    vector<vector<int>> result = floodFill(image, sr, sc, Newcolor);
    for (const auto &row : result)
    {
        for (const auto &col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }
    return 0;
}