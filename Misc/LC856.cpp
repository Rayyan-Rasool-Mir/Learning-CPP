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

int scoreOfParentheses(string s)
{
    stack<int> stk;
    stk.push(0);

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            stk.push(0);
        }
        else
        {
            int total = 0;
            int a = stk.top();
            stk.pop();

            if (a == 0)
            {
                total = 1;
            }
            else
            {
                total = 2 * a;
            }
            stk.top() += total;
        }
    }
    return stk.top();
}

int main()
{
    string s1 = "()";
    string s2 = "(())";
    string s3 = "()()";
    string s4 = "(()())";
    string s5 = "((()))";
    string s6 = "(()(()))";

    cout << "Test 1: " << scoreOfParentheses(s1) << endl; // 1
    cout << "Test 2: " << scoreOfParentheses(s2) << endl; // 2
    cout << "Test 3: " << scoreOfParentheses(s3) << endl; // 2
    cout << "Test 4: " << scoreOfParentheses(s4) << endl; // 4
    cout << "Test 5: " << scoreOfParentheses(s5) << endl; // 4
    cout << "Test 6: " << scoreOfParentheses(s6) << endl; // 6

    return 0;
}