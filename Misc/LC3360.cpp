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

bool canAliceWin(int n)
{
    int req = 10;
    bool ans = true;
    while (req > 0 && n >= req)
    {
        n -= req;
        req--;
        ans = !ans;
    }
    if (ans == false)
    {
        return true;
    }
    return false;
}

int main()
{
    int n = 15;
    bool result = canAliceWin(n);
    cout << (result ? "true" : "false") << endl;
    return 0;
}