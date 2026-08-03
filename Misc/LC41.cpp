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

int firstMissingPositive(vector<int> &nums)
{
    int ans = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        while (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1])
        {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != i + 1)
            return i + 1;
    }

    return nums.size() + 1;
}

int main()
{
    vector<vector<int>> testCases = {
        {1, 2, 0},
        {3, 4, -1, 1},
        {7, 8, 9, 11, 12},
        {1, 1},
        {2, 1},
        {2},
        {1},
        {1, 2, 3, 4},
        {4, 3, 2, 1},
        {2, 2, 2, 1}
    };

    for (auto nums : testCases)
    {
        cout << "Input: ";

        for (int x : nums)
            cout << x << " ";

        cout << "\nAnswer: " << firstMissingPositive(nums) << "\n\n";
    }

    return 0;
}