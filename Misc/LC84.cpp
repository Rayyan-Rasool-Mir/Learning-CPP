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

int largestRectangleArea(vector<int> &heights)
{
    int ans = 0;
    int n = heights.size();
    vector<int> left(n, 0);
    vector<int> right(n, 0);

    stack<int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        while (s.size() > 0 && heights[s.top()] >= heights[i])
        {
            s.pop();
        }

        if (s.empty())
        {
            right[i] = n;
        }
        else
        {
            right[i] = s.top();
        }
        s.push(i);
    }

    while (!s.empty())
    {
        s.pop();
    }

    for (int i = 0; i < n; i++)
    {
        while (s.size() > 0 && heights[s.top()] >= heights[i])
        {
            s.pop();
        }

        if (s.empty())
        {
            left[i] = -1;
        }
        else
        {
            left[i] = s.top();
        }
        s.push(i);
    }

    for (int i = 0; i < n; i++)
    {
        int width = right[i] - left[i] - 1;
        int currentArea = heights[i] * width;

        ans = max(ans, currentArea);
    }

    return ans;
}

int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3};

    int ans = largestRectangleArea(heights);

    cout << "Largest rectangle area: " << ans << endl;

    return 0;
}