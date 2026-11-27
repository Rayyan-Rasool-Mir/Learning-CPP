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

int removeElement(vector<int> &nums, int val)
{
    int i = 0;
    int j = nums.size() - 1;

    while (i <= j)
    {
        if (nums[i] == val)
        {
            swap(nums[i], nums[j]);
            j--;
        }
        else
        {
            i++;
        }
    }
    return i;
}

int main()
{
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;

    int k = removeElement(nums, val);

    cout << "k = " << k << endl;
    cout << "Modified array: ";

    for (int i = 0; i < k; i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}