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

int numOfStrings(vector<string> &patterns, string word)
{
    int ans = 0;
    for (int i = 0; i < patterns.size(); i++)
    {
        if (word.find(patterns[i]) != -1)
        {
            ans++;
        }
    }

    return ans;
}

int main()
{
    vector<string> patterns = {"a", "b", "c"};
    string word = "abc";
    int result = numOfStrings(patterns, word);
    cout << "Number of strings found: " << result << endl;
    return 0;
}