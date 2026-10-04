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

bool checkValidString(string s)
{
    int low = 0;
    int high = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            low++;
            high++;
        }
        else if (s[i] == ')')
        {
            low--;
            high--;
        }
        else if (s[i] == '*')
        {
            low--;
            high++;
        }

        low = max(low, 0);

        if (high < 0)
        {
            return false;
        }
    }
    return low == 0;
}

int main()
{
    cout << boolalpha;

    string s1 = "()";
    string s2 = "(*)";
    string s3 = "(*))";
    string s4 = "())";
    string s5 = "((((****";
    string s6 = "";

    cout << "Test 1: " << checkValidString(s1) << endl;  // true
    cout << "Test 2: " << checkValidString(s2) << endl;  // true
    cout << "Test 3: " << checkValidString(s3) << endl;  // true
    cout << "Test 4: " << checkValidString(s4) << endl;  // false
    cout << "Test 5: " << checkValidString(s5) << endl;  // true
    cout << "Test 6: " << checkValidString(s6) << endl; // true

    return 0;
}