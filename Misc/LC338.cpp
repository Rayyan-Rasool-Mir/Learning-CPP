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

vector<int> countBits(int n)
{
    vector<int> ans(n + 1);
    ans[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        ans[i] = ans[i / 2] + (i % 2);
    }

    return ans;
}

int main()
{
    int n = 5;
    vector<int> result = countBits(n);
    for (int i = 0; i <= n; i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}