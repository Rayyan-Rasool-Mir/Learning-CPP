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

int trap(vector<int> &height)
{
    if (height.empty()){
        return 0;
    }
    
    int ans = 0;
    vector<int> leftMax(height.size());
    vector<int> rightMax(height.size());
    leftMax[0] = height[0];
    rightMax[height.size() - 1] = height[height.size() - 1];

    for (int i = 1; i < height.size(); i++)
    {
        leftMax[i] = max(leftMax[i - 1], height[i]);
    }

    for (int i = height.size() - 2; i >= 0; i--)
    {
        rightMax[i] = max(rightMax[i + 1], height[i]);
    }

    for (int i = 0; i < height.size(); i++)
    {
        ans += min(leftMax[i], rightMax[i]) - height[i];
    }

    return ans;
}

int main()
{
    vector<vector<int>> testCases = {
        {0,1,0,2,1,0,1,3,2,1,2,1},
        {4,2,0,3,2,5},
        {1},
        {},
        {3,0,2,0,4}
    };

    for(auto height : testCases)
    {
        cout << "Height: ";

        for(int x : height)
            cout << x << " ";

        cout << "\nWater Trapped: " << trap(height) << "\n\n";
    }

    return 0;
}