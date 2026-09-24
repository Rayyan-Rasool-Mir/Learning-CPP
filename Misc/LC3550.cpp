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

int smallestIndex(vector<int> &nums)
{
    int size = nums.size();
    for (int i = 0; i < size; i++)
    {
        int num = nums[i];
        int sum = 0;
        while (num > 0)
        {
            sum += num % 10;
            num /= 10;
        }

        if (sum == i)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 4, 5};
    vector<int> nums2 = {10, 21, 12, 3, 4};
    vector<int> nums3 = {5, 7, 11, 13};

    cout << "Test 1: " << smallestIndex(nums1) << endl;
    cout << "Test 2: " << smallestIndex(nums2) << endl;
    cout << "Test 3: " << smallestIndex(nums3) << endl;

    return 0;
}