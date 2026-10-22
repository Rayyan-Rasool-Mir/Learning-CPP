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

int minOperations(string s)
{
    string t = s;
    sort(t.begin(), t.end());
    int n = s.size();

    if (s == t || n <= 1)
    {
        return 0;
    }

    else if (n == 2)
    {
        return -1;
    }

    else if (s[0] == t[0] || s[n - 1] == t[n - 1])
    {
        return 1;
    }

    for (int i = 1; i < n - 1; i++)
    {
        if (s[i] == t[0] || s[i] == t[n - 1])
        {
            return 2;
        }
    }

    return 3;
}

int main()
{
    vector<string> testCases = {
        "card",
        "abc",
        "cba",
        "a",
        "ab",
        "ba",
        "dcba",
        "acbd",
        "zxy",
        "aabb"
    };

    for (string s : testCases)
    {
        cout << "Input: " << s
             << " | Minimum operations: "
             << minOperations(s) << endl;
    }

    return 0;
}