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

vector<int> applyOperations(vector<int> &nums)
{
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            nums[i] *= 2;
            nums[i + 1] = 0;
        }
    }

    int j = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            nums[j] = nums[i];
            j++;
        }
    }

    while (j < nums.size())
    {
        nums[j++] = 0;
    }
    return nums;
}

int main()
{
    vector<int> nums = {1, 2, 2, 1, 1, 0};
    vector<int> result = applyOperations(nums);
    for (int num : result)
    {
        cout << num << " ";
    }
    return 0;
}