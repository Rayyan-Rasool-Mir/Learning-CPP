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

int divide(int dividend, int divisor)
{
    long long a = dividend;
    long long b = divisor;
    long long ans = 0;

    bool negative = false;
    if ((a < 0) || (b < 0))
    {
        negative = true;
    }

    if ((a < 0) && (b < 0))
    {
        negative = false;
    }

    a = abs(a);
    b = abs(b);

    while (a >= b)
    {
        long long current = b;
        long long count = 1;

        while (current + current <= a)
        {
            current += current;
            count += count;
        }

        a -= current;
        ans += count;
    }

    if (negative)
        ans = -ans;

    if (ans > INT_MAX)
        return INT_MAX;

    if (ans < INT_MIN)
        return INT_MIN;

    return ans;
}
int main()
{
    int dividend = 10;
    int divisor = 3;

    cout << divide(dividend, divisor) << endl;

    return 0;
}