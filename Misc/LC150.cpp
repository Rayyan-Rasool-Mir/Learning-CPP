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
int evalRPN(vector<string> &tokens)
{
    stack<int> s;

    for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i] == "+" || tokens[i] == "*" || tokens[i] == "-" || tokens[i] == "/")
        {
            int result = 0;
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();

            if (tokens[i] == "+")
            {
                result = a + b;
            }
            else if (tokens[i] == "*")
            {
                result = a * b;
            }
            else if (tokens[i] == "-")
            {
                result = a - b;
            }
            else if (tokens[i] == "/")
            {
                result = a / b;
            }

            s.push(result);
        }
        else
        {
            int dig = stoi(tokens[i]); // stoi => string to int function like to_string
            s.push(dig);
        }
    }

    return s.top();
}

int main()
{
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    cout << evalRPN(tokens) << endl; // Output: 9

    tokens = {"4", "13", "5", "/", "+"};
    cout << evalRPN(tokens) << endl; // Output: 6

    return 0;
}