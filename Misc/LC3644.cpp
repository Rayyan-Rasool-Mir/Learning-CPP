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

int sortPermutation(vector<int> &nums)
{
    int ans = -1;
    bool misplaced = false;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != i)
        {
            if (!misplaced)
            {
                ans = nums[i];
                misplaced = true;
            }
            else
            {
                ans &= nums[i];
            }
        }
    }

    if (!misplaced)
    {
        return 0;
    }

    return ans;
}

int main()
{
    vector<int> nums = {0, 3, 2, 1};
    int result = sortPermutation(nums);
    cout << "The bitwise AND of misplaced elements is: " << result << endl;
    return 0;
}