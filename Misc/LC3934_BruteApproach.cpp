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

int smallestUniqueSubarray(vector<int> &nums)
{
    int n = nums.size();

    for (int i = 1; i <= n; i++)
    {
        map<vector<int>, int> freq;

        for (int j = 0; j <= n - i; j++)
        {
            vector<int> subarr;

            for (int k = j; k < j + i; k++)
            {
                subarr.push_back(nums[k]);
            }

            freq[subarr]++;
        }

        for (auto &[subarr, count] : freq)
        {
            if (count == 1)
            {
                return i;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {1, 2, 1, 2, 3};

    cout << "Minimum unique subarray length: "
         << smallestUniqueSubarray(nums) << endl;

    return 0;
}