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

int minInsertions(string s)
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
            if (i + 1 < s.size() && s[i + 1] == ')')
            {
                if (open > 0)
                {
                    open--;
                }
                else
                {
                    ans++;
                }
                i++;
            }
            else
            {
                ans++;
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
    }
    return ans + 2 * open;
}

int main()
{
    cout << minInsertions("())") << endl;       // 0
    cout << minInsertions("(()))") << endl;     // 1
    cout << minInsertions("))())(") << endl;    // 3
    cout << minInsertions("((((((") << endl;    // 12
    cout << minInsertions(")))))))") << endl;   // 5

    return 0;
}