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

vector<vector<string>> groupAnagrams(vector<string> &strs)
{

    int n = strs.size();

    vector<string> sorted = strs;

    for (int i = 0; i < n; i++)
        sort(sorted[i].begin(), sorted[i].end());

    vector<vector<string>> ans;
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++)
    {
        if (visited[i])
            continue;

        vector<string> group;
        group.push_back(strs[i]);
        visited[i] = true;

        for (int j = i + 1; j < n; j++)
        {
            if (visited[j])
                continue;

            if (strs[i].size() != strs[j].size())
                continue;

            if (sorted[i] == sorted[j])
            {
                group.push_back(strs[j]);
                visited[j] = true;
            }
        }

        ans.push_back(group);
    }

    return ans;
}
int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> ans = groupAnagrams(strs);

    for (auto &group : ans)
    {
        cout << "[ ";
        for (auto &word : group)
        {
            cout << word << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}

//the main function is ai generated for simplicity