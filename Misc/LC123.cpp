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

int maxProfit(vector<int> &prices)
{
    int b1 = INT_MIN;
    int s1 = 0;
    int b2 = INT_MIN;
    int s2 = 0;

    for (int i = 0; i < prices.size(); i++)
    {
        b1 = max(b1, -prices[i]);
        s1 = max(s1, b1 + prices[i]);
        b2 = max(b2, s1 - prices[i]);
        s2 = max(s2, b2 + prices[i]);
    }

    return s2;
}

int main()
{
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int result = maxProfit(prices);
    cout << "Maximum profit: " << result << endl;
    return 0;
}