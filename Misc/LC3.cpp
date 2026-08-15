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

int lengthOfLongestSubstring(string s)
{
    vector<int> count(128, 0);

    int left = 0;
    int ans = 0;

    for (int i = 0; i < s.size(); i++)
    {
        count[s[i]]++;

        while (count[s[i]] > 1)
        {
            count[s[left]]--;
            left++;
        }

        int currentlength = i - left + 1;
        ans = max(ans, currentlength);
    }

    return ans;
}

int main()
{
    string s = "abcabcbb";

    int ans = lengthOfLongestSubstring(s);

    cout << "Longest substring length: " << ans << endl;

    return 0;
}