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

int numOfSubarrays(vector<int> &arr)
{
    int even = 1;
    int odd = 0;
    int ans = 0;
    int sum = 0;
    int mod = 1e9 + 7;

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];

        if (sum % 2 != 0)
        {
            ans += even;
            odd++;
        }
        else
        {
            ans += odd;
            even++;
        }

        ans = ans % mod;
    }

    return ans;
}

int main()
{
    vector<int> arr = {1, 3, 5};
    int result = numOfSubarrays(arr);
    cout << "Number of subarrays with odd sum: " << result << endl;
    return 0;
}