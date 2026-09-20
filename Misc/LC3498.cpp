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

int reverseDegree(string s)
{
    vector<int> revdeg(26);

    int j = 0;
    for (int i = 25; i >= 0; i--)
    {
        revdeg[j] = i + 1;
        j++;
    }

    int ans = 0;

    for (int i = 0; i < s.size(); i++)
    {
        int num = s[i] - 'a';
        ans += (i + 1) * revdeg[num];
    }

    return ans;
}

int main()
{
    cout << "Test 1: " << reverseDegree("abc") << endl; // 148
    cout << "Test 2: " << reverseDegree("z") << endl;   // 1
    cout << "Test 3: " << reverseDegree("az") << endl;  // 28
    cout << "Test 4: " << reverseDegree("leetcode") << endl;

    return 0;
}