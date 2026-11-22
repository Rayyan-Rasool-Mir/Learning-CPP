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

bool checkString(string s)
{
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i - 1] == 'b' && s[i] == 'a')
        {
            return false;
        }
    }

    return true;
}

int main()
{
    string s = "aaabbb";
    bool result = checkString(s);
    cout << (result ? "true" : "false") << endl;
    return 0;
}