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

int jump(vector<int> &nums)
{
    int jmp = 0;
    int current = 0;
    int farthest = 0;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        farthest = max(farthest, i + nums[i]);

        if (i == current)
        {
            jmp++;
            current = farthest;
        }
    }

    return jmp;
}

int main()
{
    vector<int> nums = {2, 3, 1, 1, 4};

    int ans = jump(nums);

    cout << "Minimum jumps: " << ans << endl;

    return 0;
}