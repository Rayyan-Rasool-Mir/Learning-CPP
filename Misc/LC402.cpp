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

string removeKdigits(string num, int k)
{
    stack<char> st;
    string ans = "";

    for (int i = 0; i < num.size(); i++)
    {
        while (!st.empty() && k > 0 && st.top() > num[i])
        {
            st.pop();
            k--;
        }

        st.push(num[i]);
    }

    while (k > 0)
    {
        st.pop();
        k--;
    }

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    int i = 0;

    while (i < ans.size() && ans[i] == '0')
    {
        i++;
    }

    ans = ans.substr(i);

    if (ans.empty())
    {
        return "0";
    }

    return ans;
}

int main()
{
    cout << removeKdigits("1432219", 3) << endl; // 1219
    cout << removeKdigits("10200", 1) << endl;   // 200
    cout << removeKdigits("10", 2) << endl;      // 0
    cout << removeKdigits("12345", 2) << endl;   // 123
    cout << removeKdigits("112", 1) << endl;     // 11
    cout << removeKdigits("10001", 1) << endl;   // 1

    return 0;
}
