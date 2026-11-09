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

int minimumPushes(string word)
{
    int n = word.size();
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int p = (i / 8) + 1;
        ans += p;
    }

    return ans;
}

int main()
{
    string word = "hello";
    int result = minimumPushes(word);
    cout << "Minimum number of pushes required: " << result << endl;
    return 0;
}