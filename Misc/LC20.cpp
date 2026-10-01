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

bool isValid(string s)
{
    stack<char> stk;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '[' || s[i] == '(' || s[i] == '{')
        {
            stk.push(s[i]);
        }
        else
        {
            if (stk.empty())
            {
                return false;
            }
            char top = stk.top();
            if (top == '(' && s[i] != ')')
            {
                return false;
            }
            if (top == '{' && s[i] != '}')
            {
                return false;
            }
            if (top == '[' && s[i] != ']')
            {
                return false;
            }
            stk.pop();
        }
    }
    return stk.empty();
}

int main()
{
    string s1 = "()";
    string s2 = "()[]{}";
    string s3 = "(]";
    string s4 = "([)]";
    string s5 = "{[]}";
    string s6 = "(((";
    string s7 = "}";
    string s8 = "";

    cout << boolalpha;

    cout << "Test 1: " << isValid(s1) << endl; // true
    cout << "Test 2: " << isValid(s2) << endl; // true
    cout << "Test 3: " << isValid(s3) << endl; // false
    cout << "Test 4: " << isValid(s4) << endl; // false
    cout << "Test 5: " << isValid(s5) << endl; // true
    cout << "Test 6: " << isValid(s6) << endl; // false
    cout << "Test 7: " << isValid(s7) << endl; // false
    cout << "Test 8: " << isValid(s8) << endl; // true

    return 0;
}