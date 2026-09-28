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

int maxDepth(string s)
{
    int count = 0;
    int maxDepth = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            count++;
            maxDepth = max(maxDepth, count);
        }

        else if (s[i] == ')')
        {
            count--;
        }
    }
    return maxDepth;
}

int main()
{
    string s1 = "(1+(2*3)+((8)/4))+1";

    cout << "Test 1: " << maxDepth(s1) << endl;

    return 0;
}