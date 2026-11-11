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

int calculate(string s)
{
    long long result = 0;
    long long num = 0;
    long long sign = 1;
    stack<long long> st;

    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]))
        { // s[i] is a digit
            num = num * 10 + (s[i] - '0');
        }

        else if (s[i] == '+')
        {
            result += num * sign;
            num = 0;
            sign = 1;
        }

        else if (s[i] == '-')
        {
            result += num * sign;
            num = 0;
            sign = -1;
        }

        else if (s[i] == '(')
        {
            st.push(result);
            st.push(sign);
            result = 0;
            sign = 1;
        }

        else if (s[i] == ')')
        {
            result += num * sign;
            num = 0;

            result *= st.top();
            st.pop();

            result += st.top();
            st.pop();
        }

        else if (s[i] == ' ')
        {
            continue;
        }
    }

    result += num * sign;
    return result;
}

int main()
{
    string s = "(1+(4+5+2)-3)+(6+8)";
    int result = calculate(s);
    cout << "Result of the expression: " << result << endl;

    string s2 = "-2147483648";
    int result2 = calculate(s2);
    cout << "Result of the expression: " << result2 << endl;
    return 0;
}