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

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> merge = nums1;
    merge.insert(merge.end(), nums2.begin(), nums2.end());

    sort(merge.begin(), merge.end());
    int n = merge.size();

    double median;

    if (n % 2 == 0)
    {
        median = (merge[n / 2 - 1] + merge[n / 2]) / 2.0;
    }
    else
    {
        median = merge[n / 2];
    }

    return median;
}

int main()
{
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    cout << findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}