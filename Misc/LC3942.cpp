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

int checkRot(vector<int> &nums, vector<int> &temp, int n)
{
    for (int k = 0; k < n; k++)
    {
        bool valid = true;

        for (int i = 0; i < n; i++)
        {
            if (nums[(k + i) % n] != temp[i])
            {
                valid = false;
                break;
            }
        }

        if (valid)
        {
            return k;
        }
    }
    return -1;
}

int minOperations(vector<int> &nums)
{
    int n = nums.size();
    vector<int> temp = nums;
    sort(temp.begin(), temp.end());

    if (nums == temp)
    {
        return 0;
    }

    int check = checkRot(nums, temp, n);
    int ans = -1;

    if (check != -1)
    {
        int rshift = (n - check) % n + 2;
        int lshift = check;
        ans = min(rshift, lshift);
    }

    vector<int> rev = nums;
    reverse(rev.begin(), rev.end());

    check = checkRot(rev, temp, n);

    if (check != -1)
    {
        int rshift = 1 + (n - check) % n;
        int lshift = 1 + check;

        int fin = min(rshift, lshift);

        if (ans == -1)
        {
            ans = fin;
        }
        else
        {
            ans = min(ans, fin);
        }
    }

    return ans;
}

int main()
{
    vector<int> temp = {3, 4, 5, 1, 2};
    cout << minOperations(temp) << endl;

    vector<int> temp2 = {2, 1, 3, 4};
    cout << minOperations(temp2) << endl;

    vector<int> temp3 = {1, 2, 3};
    cout << minOperations(temp3) << endl;
    
    return 0;
}