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

bool uniformArray(vector<int> &nums1)
{
    int minimum = INT_MAX;

    for (int i = 0; i < nums1.size(); i++)
    {
        minimum = min(minimum, nums1[i]);
    }

    if (minimum % 2 != 0)
    {
        return true;
    }
    else
    {
        for (int i = 0; i < nums1.size(); i++)
        {
            if (nums1[i] % 2 != 0)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    vector<int> nums1 = {1, 2, 4};

    cout << uniformArray(nums1) << endl;

    return 0;
}