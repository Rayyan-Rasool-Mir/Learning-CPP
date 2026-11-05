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

int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
{
    int ans = 0;
    for (int i = 0; i < arr1.size(); i++)
    {
        bool valid = true;

        for (int j = 0; j < arr2.size(); j++)
        {
            if (abs(arr1[i] - arr2[j]) <= d)
            {
                valid = false;
                break;
            }
        }

        if (valid)
        {
            ans++;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr1 = {4, 5, 8};
    vector<int> arr2 = {10, 9, 1, 8};
    int d = 2;
    int result = findTheDistanceValue(arr1, arr2, d);
    cout << "The distance value is: " << result << endl;
    return 0;
}