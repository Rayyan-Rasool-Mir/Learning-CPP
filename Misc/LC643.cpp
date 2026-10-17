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

double findMaxAverage(vector<int> &nums, int k)
{
    double sum;

    for (int i = 0; i < k; i++)
    {
        sum += nums[i];
    }

    double ans = sum;

    for (int i = k; i < nums.size(); i++)
    {
        sum += nums[i] - nums[i - k];
        ans = max(ans, sum);
    }
    return ans / k;
}

int main()
{
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;
    cout << findMaxAverage(nums, k) << endl;
    return 0;
}