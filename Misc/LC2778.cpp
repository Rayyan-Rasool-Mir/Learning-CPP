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

int sumOfSquares(vector<int> &nums)
{
    int ans = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if ((nums.size() % (i + 1)) == 0)
        {
            ans += (nums[i] * nums[i]);
        }
    }

    return ans;
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> nums2 = {2, 7, 1, 19, 18, 3};
    vector<int> nums3 = {1, 2, 3};

    cout << sumOfSquares(nums1) << endl; // 21
    cout << sumOfSquares(nums2) << endl; // 384
    cout << sumOfSquares(nums3) << endl; // 10

    return 0;
}