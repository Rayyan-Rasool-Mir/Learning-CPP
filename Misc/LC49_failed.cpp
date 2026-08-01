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

//this failed due to tle
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    vector<vector<string>> ans;
    vector<bool> visited(strs.size(), false);
    for (int i = 0; i < strs.size(); i++)
    {
        if (visited[i])
        {
            continue;
        }
        string temp = strs[i];
        sort(temp.begin(), temp.end());
        vector<string> group;
        group.push_back(strs[i]);
        visited[i] = true;
        for (int j = i + 1; j < strs.size(); j++)
        {
            string temp2 = strs[j];
            sort(temp2.begin(), temp2.end());
            if (temp == temp2)
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