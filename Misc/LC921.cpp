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

int minAddToMakeValid(string s)
{
    int open = 0;
    int ans = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            open++;
        }
        else
        {
            if (open > 0)
            {
                open--;
            }
            else
            {
                ans++;
            }
        }
    }
    return ans += open;
}

int main()
{
    string s1 = "())";
    string s2 = "(((";
    string s3 = "()";
    string s4 = "()))((";
    string s5 = "";

    cout << "Test 1: " << minAddToMakeValid(s1) << endl; // 1
    cout << "Test 2: " << minAddToMakeValid(s2) << endl; // 3
    cout << "Test 3: " << minAddToMakeValid(s3) << endl; // 0
    cout << "Test 4: " << minAddToMakeValid(s4) << endl; // 4
    cout << "Test 5: " << minAddToMakeValid(s5) << endl; // 0

    return 0;
}