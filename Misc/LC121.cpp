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
    int profit = 0;
    int price = INT_MAX;

    for (int i = 0; i < prices.size(); i++)
    {
        price = min(price, prices[i]);
        int currentProfit = prices[i] - price;

        profit = max(profit, currentProfit);
    }

    return profit;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << maxProfit(prices) << endl;

    return 0;
}