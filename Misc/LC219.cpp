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

bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    unordered_set<int> st;
    for (int i = 0; i < nums.size(); i++)
    {
        if (st.find(nums[i]) != st.end())
        {
            return true;
        }

        st.insert(nums[i]);

        if (st.size() > k)
        {
            st.erase(nums[i - k]);
        }
    }

    return false;
}

int main()
{
    vector<int> nums = {1, 2, 3, 1};
    int k = 3;
    bool result = containsNearbyDuplicate(nums, k);
    cout << "Contains nearby duplicate: " << boolalpha << result << endl;
    return 0;
}