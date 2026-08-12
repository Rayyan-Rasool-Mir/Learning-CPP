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

vector<string> fullJustify(vector<string> &words, int maxWidth)
{
    int i = 0;
    vector<string> ans;
    while (i < words.size())
    {
        int start = i;
        int currentlength = 0;

        while (i < words.size() && currentlength + words[i].size() + (i - start) <= maxWidth)
        {

            currentlength += words[i].size();
            i++;
        }

        int end = i - 1;

        if (i == words.size())
        {
            string line = "";
            for (int j = start; j <= end; j++)
            {
                line += words[j];

                if (j != end)
                {
                    line += " ";
                }
            }

            line += string(maxWidth - line.size(), ' ');
            ans.push_back(line);
        }
        else if (start == end)
        {
            string line = words[start];
            line += string(maxWidth - line.size(), ' ');
            ans.push_back(line);
        }

        else
        {
            string line = "";
            int totalspace = maxWidth - currentlength;
            int gaps = end - start;
            int spaceeach = totalspace / gaps;
            int extraspace = totalspace % gaps;

            for (int j = start; j <= end; j++)
            {
                line += words[j];

                if (j != end)
                {
                    line += string(spaceeach, ' ');

                    if (extraspace > 0)
                    {
                        line += ' ';
                        extraspace--;
                    }
                }
            }
            ans.push_back(line);
        }
    }

    return ans;
}

int main()
{
    vector<string> words = {
        "This", "is", "an", "example", "of",
        "text", "justification."
    };

    int maxWidth = 16;

    vector<string> ans = fullJustify(words, maxWidth);

    for(string line : ans)
    {
        cout << "|" << line << "|" << endl;
    }

    return 0;
}