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

int numRabbits(vector<int> &answers)
{
    vector<int> freq(1000, 0);
    int ans = 0;

    for (int i = 0; i < answers.size(); i++)
    {
        freq[answers[i]]++;
    }

    for (int i = 0; i < 1000; i++)
    {
        if (freq[i] > 0)
        {
            int groupsize = i + 1;
            int group = (freq[i] + groupsize - 1) / groupsize;
            ans += group * groupsize;
        }
    }
    return ans;
}

int main()
{
    vector<int> answers = {1, 1, 2};

    cout << numRabbits(answers) << endl;

    return 0;
}