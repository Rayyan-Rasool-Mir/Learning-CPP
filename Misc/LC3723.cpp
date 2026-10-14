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

string maxSumOfSquares(int num, int sum)
{
    string ans = "";

    if (sum > 9 * num)
    {
        return ans;
    }

    while (num > 0)
    {
        int digit = min(9, sum);
        ans += to_string(digit);
        sum -= digit;
        num--;
    }
    return ans;
}

int main()
{
    cout << maxSumOfSquares(3, 20) << endl;  // 992
    cout << maxSumOfSquares(4, 23) << endl;  // 9950
    cout << maxSumOfSquares(2, 18) << endl;  // 99
    cout << maxSumOfSquares(2, 20) << endl;  // ""
    cout << maxSumOfSquares(3, 1) << endl;   // 100

    return 0;
}