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

string reverseParentheses(string s)
{
    stack<string> stk;
    stk.push("");

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            stk.push("");
        }
        else if ('a' <= s[i] && s[i] <= 'z')
        {
            stk.top() += s[i];
        }
        else if (s[i] == ')')
        {
            string temp = stk.top();
            stk.pop();
            reverse(temp.begin(), temp.end());
            stk.top() += temp;
        }
    }
    return stk.top();
}

int main()
{
    string s1 = "(abcd)";
    string s2 = "(u(love)i)";
    string s3 = "(ed(et(oc))el)";

    cout << "Test 1: " << reverseParentheses(s1) << endl; // dcba
    cout << "Test 2: " << reverseParentheses(s2) << endl; // iloveu
    cout << "Test 3: " << reverseParentheses(s3) << endl; // leetcode

    return 0;
}