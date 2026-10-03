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

int longestValidParentheses(string s)
{
    stack<int> stk;
    stk.push(-1);
    int maxLength = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            stk.push(i);
        }
        else
        {
            stk.pop();

            if (stk.empty())
            {
                stk.push(i);
            }
            else
            {
                int length = i - stk.top();
                maxLength = max(length, maxLength);
            }
        }
    }
    return maxLength;
}

int main()
{
    string s1 = "(()";
    string s2 = ")()())";
    string s3 = "";
    string s4 = "()(()";
    string s5 = "()()";
    string s6 = "((()))";
    string s7 = ")(())()";

    cout << "Test 1: " << longestValidParentheses(s1) << endl; // 2
    cout << "Test 2: " << longestValidParentheses(s2) << endl; // 4
    cout << "Test 3: " << longestValidParentheses(s3) << endl; // 0
    cout << "Test 4: " << longestValidParentheses(s4) << endl; // 2
    cout << "Test 5: " << longestValidParentheses(s5) << endl; // 4
    cout << "Test 6: " << longestValidParentheses(s6) << endl; // 6
    cout << "Test 7: " << longestValidParentheses(s7) << endl; // 6

    return 0;
}