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

void backtrack(string current, int open, int close, int n, vector<string> &ans)
{
    if (current.size() == 2 * n)
    {
        ans.push_back(current);
        return;
    }

    if (open < n)
    {
        backtrack(current + '(', open + 1, close, n, ans);
    }

    if (close < open)
    {
        backtrack(current + ')', open, close + 1, n, ans);
    }
}
vector<string> generateParenthesis(int n)
{
    vector<string> ans;
    backtrack("", 0, 0, n, ans);
    return ans;
}

int main()
{
    int n1 = 1;
    int n2 = 2;
    int n3 = 3;
    int n4 = 4;

    vector<string> ans1 = generateParenthesis(n1);
    vector<string> ans2 = generateParenthesis(n2);
    vector<string> ans3 = generateParenthesis(n3);
    vector<string> ans4 = generateParenthesis(n4);

    cout << "Test 1: ";
    for (string s : ans1)
        cout << s << " ";
    cout << endl;

    cout << "Test 2: ";
    for (string s : ans2)
        cout << s << " ";
    cout << endl;

    cout << "Test 3: ";
    for (string s : ans3)
        cout << s << " ";
    cout << endl;

    cout << "Test 4: ";
    for (string s : ans4)
        cout << s << " ";
    cout << endl;

    return 0;
}