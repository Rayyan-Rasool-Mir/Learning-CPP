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
// 0-999 ==> 0
// 1,000-999,999 ==> 1
// 1,000,000-999,999,999 ==> 2
// 1,000,000,000-999,999,999,999 ==> 3
// 1,000,000,000,000-999,999,999,999,999 ==> 4
long long countCommas(long long n)
{
    long long count = 0;

    if (n >= 1000)
    {
        long long end = min(n, 999999LL);
        count += (end - 1000 + 1) * 1;
    }
    if (n >= 1000000)
    {
        long long end = min(n, 999999999LL);
        count += (end - 1000000 + 1) * 2;
    }
    if (n >= 1000000000)
    {
        long long end = min(n, 999999999999LL);
        count += (end - 1000000000 + 1) * 3;
    }
    if (n >= 1000000000000)
    {
        long long end = min(n, 999999999999999LL);
        count += (end - 1000000000000 + 1) * 4;
    }
    if (n >= 1000000000000000LL)
    {
        long long end = min(n, 999999999999999999LL);
        count += (end - 1000000000000000LL + 1) * 5;
    }
    return count;
}

int main()
{
    cout << countCommas(1002) << endl;
    cout << countCommas(998) << endl;
    cout << countCommas(1000000) << endl;
    cout << countCommas(1000000000000000LL) << endl;

    return 0;
}