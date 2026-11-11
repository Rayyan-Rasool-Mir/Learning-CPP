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

long long minimumCost(long long cost1, long long cost2, long long costBoth, long long need1, long long need2)
{
    long long t1 = need1 * cost1 + need2 * cost2;

    long long common = min(need1, need2);

    long long t2 = common * costBoth + (need1 - common) * cost1 + (need2 - common) * cost2;

    long long t3 = max(need1, need2) * costBoth;

    return min(t1, min(t2, t3));
}

int main()
{
    long long cost1 = 2;
    long long cost2 = 3;
    long long costBoth = 4;
    long long need1 = 5;
    long long need2 = 6;
    long long result = minimumCost(cost1, cost2, costBoth, need1, need2);
    cout << "Minimum cost: " << result << endl;

    return 0;
}