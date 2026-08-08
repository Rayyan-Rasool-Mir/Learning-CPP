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

int candy(vector<int> &ratings)
{
    vector<int> left_candies(ratings.size(), 1);

    for (int i = 1; i < ratings.size(); i++)
    {
        if (ratings[i] > ratings[i - 1])
        {
            left_candies[i] = left_candies[i - 1] + 1;
        }
    }

    for (int i = ratings.size() - 2; i >= 0; i--)
    {
        if (ratings[i] > ratings[i + 1])
        {
            left_candies[i] = max(left_candies[i], left_candies[i + 1] + 1);
        }
    }

    int ans = 0;
    for (int i = 0; i < ratings.size(); i++)
    {
        ans += left_candies[i];
    }

    return ans;
}

int main()
{
    vector<vector<int>> tests = {
        {1,0,2},
        {1,2,2},
        {1,3,4,5,2},
        {5,4,3,2,1},
        {1,2,3,4,5},
        {1},
        {1,3,2,2,1}
    };

    for(auto ratings : tests)
    {
        cout << "Ratings: ";
        for(int x : ratings)
            cout << x << " ";

        cout << "\nCandies: " << candy(ratings) << "\n\n";
    }

    return 0;
}