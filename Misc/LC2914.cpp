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

int minChanges(string s)
{
    int changes = 0;

    for (int i = 0; i < s.size(); i += 2)
    {
        if (s[i] != s[i + 1])
        {
            changes++;
        }
    }
    return changes;
}

int main()
{
    string s = "010101";
    int result = minChanges(s);
    cout << result << endl;
    return 0;
}