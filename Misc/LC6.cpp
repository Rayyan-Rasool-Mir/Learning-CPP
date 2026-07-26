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

string convert(string s, int numRows)
{
    if (numRows == 1)
    {
        return s;
    }

    vector<string> rows(numRows);
    string ans = "";

    int currentrow = 0;
    bool goingdown = false;

    for (int i = 0; i < s.size(); i++)
    {
        rows[currentrow] += s[i];

        if (currentrow == 0)
        {
            goingdown = true;
        }
        if (currentrow == numRows - 1)
        {
            goingdown = false;
        }
        if (goingdown)
        {
            currentrow++;
        }
        else
        {
            currentrow--;
        }
    }

    for (int i = 0; i < numRows; i++)
    {
        ans += rows[i];
    }

    return ans;
}

int main()
{
    string s;
    int numRows;

    cin >> s;
    cin >> numRows;

    cout << convert(s, numRows);

    return 0;
}