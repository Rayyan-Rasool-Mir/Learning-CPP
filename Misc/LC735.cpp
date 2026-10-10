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

vector<int> asteroidCollision(vector<int> &asteroids)
{
    stack<int> st;
    for (int i = 0; i < asteroids.size(); i++)
    {
        bool alive = true;

        while (alive && !st.empty() && st.top() > 0 && asteroids[i] < 0)
        {
            if (st.top() < abs(asteroids[i]))
            {
                st.pop();
            }
            else if (st.top() == abs(asteroids[i]))
            {
                st.pop();
                alive = false;
            }
            else
            {
                alive = false;
            }
        }

        if (alive)
        {
            st.push(asteroids[i]);
        }
    }

    vector<int> ans;

    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    vector<int> a1 = {5, 10, -5};
    vector<int> a2 = {8, -8};
    vector<int> a3 = {10, 2, -5};
    vector<int> a4 = {-2, -1, 1, 2};
    vector<int> a5 = {1, -2, -2, -2};

    vector<vector<int>> tests = {a1, a2, a3, a4, a5};

    for (auto &asteroids : tests)
    {
        vector<int> ans = asteroidCollision(asteroids);

        cout << "[";
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i];
            if (i < ans.size() - 1)
                cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}