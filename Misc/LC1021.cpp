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

string removeOuterParentheses(string s)
{
    int d = 0;
    string ans = "";

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            if (d > 0)
            {
                ans += '(';
            }
            d++;
        }
        else
        {
            d--;
            if (d > 0)
            {
                ans += ')';
            }
        }
    }
    return ans;
}

int main()
{
    string s1 = "(()())(())";
    string s2 = "(()())(())(()(()))";
    string s3 = "()()";

    cout << removeOuterParentheses(s1) << endl;
    cout << removeOuterParentheses(s2) << endl;
    cout << removeOuterParentheses(s3) << endl;

    return 0;
}