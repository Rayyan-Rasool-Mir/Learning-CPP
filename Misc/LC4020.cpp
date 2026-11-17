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

int elevatorRequests(int n, vector<int> &requests)
{
    int ans = 0;
    int current = 0;
    for (int i = 0; i < requests.size(); i++)
    {
        ans += abs(requests[i] - current);
        current = requests[i];
    }

    return ans;
}

int main()
{
    vector<int> requests = {1, 2, 3, 4, 5};
    int n = 5;
    int result = elevatorRequests(n, requests);
    cout << "Total elevator movement: " << result << endl;
    return 0;
}