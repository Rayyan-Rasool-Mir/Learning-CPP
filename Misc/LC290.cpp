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

bool wordPattern(string pattern, string s)
{

    string word = "";
    vector<string> words;
    vector<string> used;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ')
        {
            word += s[i];
        }
        else
        {
            words.push_back(word);
            word = "";
        }
    }
    words.push_back(word);

    if (pattern.size() != words.size())
    {
        return false;
    }

    vector<string> mapping(26, "");

    for (int i = 0; i < pattern.size(); i++)
    {
        if (mapping[pattern[i] - 'a'] != "")
        {
            if (mapping[pattern[i] - 'a'] != words[i])
            {
                return false;
            }
        }
        else
        {
            for (int j = 0; j < used.size(); j++)
            {
                if (used[j] == words[i])
                {
                    return false;
                }
            }
            mapping[pattern[i] - 'a'] = words[i];
            used.push_back(words[i]);
        }
    }

    return true;
}

int main()
{
    cout << boolalpha;

    cout << "Test 1: " << wordPattern("abba", "dog cat cat dog") << endl; // true

    cout << "Test 2: " << wordPattern("abba", "dog cat cat fish") << endl; // false

    cout << "Test 3: " << wordPattern("aaaa", "dog dog dog dog") << endl; // true

    cout << "Test 4: " << wordPattern("abba", "dog dog dog dog") << endl; // false

    cout << "Test 5: " << wordPattern("abc", "dog cat dog") << endl; // false

    return 0;
}