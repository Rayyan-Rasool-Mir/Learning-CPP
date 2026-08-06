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

string reverseWords(string s)
{
    string ans = s;
    reverse(ans.begin(), ans.end());
    int n = s.size();

    int i = 0;
    while (i < n)
    {
        if (ans[i] == ' ')
        {
            i++;
            continue;
        }

        int start = i;
        while (i < n && ans[i] != ' ')
        {
            i++;
        }

        reverse(ans.begin() + start, ans.begin() + i);
    }
    // removint the extraspaces between words
    int a = 0;
    int b = 0;

    while (a < n)
    {
        while (a < n && ans[a] == ' ')
        {
            a++;
        }

        while (a < n && ans[a] != ' ')
        {
            ans[b] = ans[a];
            b++;
            a++;
        }

        while (a < n && ans[a] == ' ')
        {
            a++;
        }
        if (a < n)
        {
            ans[b] = ' ';
            b++;
        }
    }
    ans.resize(b);

    return ans;
}

int main()
{
    vector<string> tests = {
        "the sky is blue",
        "  hello world  ",
        "a good   example",
        "    ",
        "single"
    };

    for (string s : tests)
    {
        cout << "\"" << s << "\"" << endl;
        cout << "\"" << reverseWords(s) << "\"" << endl;
        cout << "-----------------\n";
    }

    return 0;
}