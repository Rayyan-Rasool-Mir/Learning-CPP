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

vector<int> findAnagrams(string s, string p)
{
    vector<int> ans;

    if (p.size() > s.size())
    {
        return ans;
    }

    vector<int> scount(26, 0);
    vector<int> pcount(26, 0);

    for (int i = 0; i < p.size(); i++)
    {
        int idx = p[i] - 'a';
        pcount[idx]++;
    }

    int j = 0;

    for (int i = 0; i < s.size(); i++)
    {
        scount[s[i] - 'a']++;

        if (i - j + 1 > p.size())
        {
            scount[s[j] - 'a']--;
            j++;
        }

        if (i - j + 1 == p.size())
        {
            if (scount == pcount)
            {
                ans.push_back(j);
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> result = findAnagrams("cbaebabacd", "abc");
    for (int i : result)
    {
        cout << i << " ";
    }
    return 0;
}