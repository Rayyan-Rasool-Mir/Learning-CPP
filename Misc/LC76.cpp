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

string minWindow(string s, string t)
{
    vector<int> need(128, 0);
    vector<int> window(128, 0);

    int left = 0;
    int start = 0;
    int formed = 0;
    int required = 0;

    for (int i = 0; i < t.size(); i++)
    {
        if (need[t[i]] == 0)
        {
            required++;
        }
        need[t[i]]++;
    }
    int minLength = INT_MAX;

    for (int right = 0; right < s.size(); right++)
    {
        window[s[right]]++;
        if (window[s[right]] == need[s[right]])
        { // need[s[right]] > 0
            formed++;
        }

        while (formed == required)
        {
            if (right - left + 1 < minLength)
            {
                minLength = right - left + 1;
                start = left;
            }

            window[s[left]]--;
            if (need[s[left]] > 0 && window[s[left]] < need[s[left]])
            {
                formed--;
            }

            left++;
        }
    }

    if (minLength == INT_MAX)
        return "";

    return s.substr(start, minLength);
}

int main()
{
    vector<pair<string, string>> tests = {
        {"ADOBECODEBANC", "ABC"}, 
        {"a", "a"},
        {"a", "aa"},
        {"aa", "aa"},
        {"ab", "b"},
        {"a", "b"},
        {"cabwefgewcwaefgcf", "cae"}
    };

    for(auto test : tests)
    {
        cout << "s = " << test.first
             << ", t = " << test.second
             << " -> " << minWindow(test.first, test.second)
             << endl;
    }

    return 0;
}