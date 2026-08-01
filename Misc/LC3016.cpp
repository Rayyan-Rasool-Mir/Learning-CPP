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

int minimumPushes(string strs)
{
    vector<int> cnt(26);
    for (int i = 0; i < strs.size(); i++)
    {
        int index = strs[i] - 'a';
        cnt[index]++;
    }
    sort(cnt.begin(), cnt.end());
    reverse(cnt.begin(), cnt.end());

    int ans = 0;

    for (int i = 0; i < 26; i++)
    {
        int cost = (i / 8) + 1;
        ans += cnt[i] * cost;
    }

    return ans;
}

int main()
{
    string word = "abcde";

    cout << minimumPushes(word);

    return 0;
}