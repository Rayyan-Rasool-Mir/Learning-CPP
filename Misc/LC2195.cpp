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

long long sum(long long a, long long b)
{
    return (a + b) * (b - a + 1) / 2;
}
long long minimalKSum(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());

    long long current = 1;
    long long remaining = k;
    long long ans = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        long long num = nums[i];
        if (num < current)
        {
            continue;
        }

        if (num > current)
        {
            long long count = min(remaining, num - current);

            ans += sum(current, current + count - 1);
            remaining -= count;

            if (remaining == 0)
            {
                return ans;
            }
        }
        current = num + 1;
    }

    if (remaining > 0)
    {
        ans += sum(current, current + remaining - 1);
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 4, 25, 10, 25};
    int k = 2;
    cout << "Minimal K Sum is: " << minimalKSum(nums, k) << endl;
    return 0;
}