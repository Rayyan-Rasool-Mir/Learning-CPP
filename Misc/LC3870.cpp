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

int countCommas(int n)
{
    int count = 0;
    if (n < 1000)
    {
        return 0;
    }
    else if (n >= 1000 && n <= 100000)
    {
        int temp = 1000;
        while (true)
        {
            if (temp <= n)
            {
                count++;
                temp++;
            }
            else if (temp > n)
            {
                break;
            }
        }
        return count;
    }

    return 0;
}

int main()
{
    int n;
    cin >> n;
    cout << countCommas(n) << "\n";

    return 0;
}