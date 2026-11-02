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

int minMoves2(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    int median = nums[nums.size() / 2];
    int ans = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        ans += abs(nums[i] - median);
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    cout << "Minimum moves to equal array elements is: " << minMoves2(nums) << endl;
    return 0;
}