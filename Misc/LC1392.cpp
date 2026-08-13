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

string longestPrefix(string s)
{
    int n = s.size();
    int i = 1;
    int len = 0;

    vector<int> arr(n, 0);

    while (i < n)
    {
        if (s[i] == s[len])
        {
            len++;
            arr[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = arr[len - 1];
            }
            else
            {
                arr[i] = 0;
                i++;
            }
        }
    }

    string ans = "";
    ans = s.substr(0, len);
    return ans;
}

int main()
{
    vector<string> tests = {
        "level",
        "ababab",
        "leetcodeleet",
        "a",
        "aaaa",
        "abcabc"
    };

    for(string s : tests)
    {
        cout << "String: " << s << endl;
        cout << "Longest happy prefix: " << longestPrefix(s) << endl;
        cout << endl;
    }

    return 0;
}