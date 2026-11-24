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

int maxLength(vector<int> &nums)
{
    size_t ans = 0;

    for (size_t i = 0; i < nums.size(); i++)
    {
        long long p = 1;
        long long g = 0;
        long long l = 1;

        for (size_t j = i; j < nums.size(); j++)
        {
            p *= nums[j];
            g = gcd(g, (long long)nums[j]);
            l = lcm(l, (long long)nums[j]);

            if (p == g * l)
            {
                ans = max(ans, j - i + 1);
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {4, 3, 6, 2, 8};
    int result = maxLength(nums);
    cout << result << endl;
    return 0;
}