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

int findContentChildren(vector<int> &g, vector<int> &s)
{
    int content = 0;
    int child = 0;
    int cookie = 0;
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    while (child < g.size() && cookie < s.size())
    {

        if (s[cookie] >= g[child])
        {
            content++;
            cookie++;
            child++;
        }
        else
        {
            cookie++;
        }
    }

    return content;
}

int main()
{
    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};

    int ans = findContentChildren(g, s);

    cout << "Content children: " << ans << endl;

    return 0;
}