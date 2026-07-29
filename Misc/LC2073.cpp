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

int timeRequiredToBuy(vector<int> &tickets, int k)
{
    int ans = 0;

    for (int i = 0; i < tickets.size(); i++)
    {
        if (i <= k)
        {
            ans += min(tickets[i], tickets[k]);
        }
        else
        {
            ans += min(tickets[i], tickets[k] - 1);
        }
    }

    return ans;
}

int main()
{
    vector<int> tickets = {2, 3, 2};
    int k = 2;

    cout << timeRequiredToBuy(tickets, k);

    return 0;
}