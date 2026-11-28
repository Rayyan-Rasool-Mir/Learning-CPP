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

int searchInsert(vector<int> &nums, int target)
{
    int st = 0;
    int end = nums.size() - 1;
    while (st <= end)
    {
        int mid = st + ((end - st) / 2);
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }
    return st;
}

int main()
{
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;
    int result = searchInsert(nums, target);
    cout << result << endl;
    return 0;
}