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

bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j <= min(i + k, (int)nums.size() - 1); j++)
        {
            if (nums[i] == nums[j])
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    vector<int> nums = {1, 2, 3, 1};
    int k = 3;
    bool result = containsNearbyDuplicate(nums, k);
    cout << "Contains nearby duplicate: " << result << endl;
    return 0;
}