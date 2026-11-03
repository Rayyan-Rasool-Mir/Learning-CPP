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

int minMoves(vector<int> &nums)
{
    int maxi = *max_element(nums.begin(), nums.end());
    int ans = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        ans += maxi - nums[i];
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    cout << "Minimum moves to equal array elements is: " << minMoves(nums) << endl;
    return 0;
}