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

int minimizeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();

    return min({nums[n - 3] - nums[0], nums[n - 2] - nums[1], nums[n - 1] - nums[2]});
}

int main()
{
    vector<int> nums = {1,4,7,8,5};
    int result = minimizeSum(nums);
    cout << result << endl;
    return 0;
}