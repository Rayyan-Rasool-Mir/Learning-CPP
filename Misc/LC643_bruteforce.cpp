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
    double ans = 0;
    vector<double> s;
    int left = 0;
    int right = k;

    for (int i = 0; i < nums.size() - k + 1; i++)
    {
        double sum = 0;
        for (int j = left; j < right && j < nums.size(); j++)
        {
            sum += nums[j];
        }
        left++;
        right++;
        s.push_back(sum);
    }

    sort(s.begin(), s.end());

    return s[s.size() - 1] / k;
}

int main()
{
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;
    cout << findMaxAverage(nums, k) << endl; // Output: 12.75
    return 0;
}