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

int climbStairs(int n)
{
    if (n <= 3)
    {
        return n;
    }

    int prev1 = 1;
    int prev2 = 2;

    for (int i = 3; i <= n; i++)
    {
        int current = prev1 + prev2;
        prev1 = prev2;
        prev2 = current;
    }

    return prev2;
}

int main()
{
    int n = 5;

    cout << "Number of ways: " << climbStairs(n) << endl;

    return 0;
}