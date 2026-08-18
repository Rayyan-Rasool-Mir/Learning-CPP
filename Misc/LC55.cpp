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

bool canJump(vector<int> &nums)
{
    int farthest = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (i > farthest)
        {
            return false;
        }

        farthest = max(farthest, i + nums[i]);

        if (farthest >= nums.size() - 1)
        {
            return true;
        }
    }

    return true;
}

int main()
{
    vector<int> nums = {2, 3, 1, 1, 4};

    bool result = canJump(nums);

    if(result){
        cout << "true" << endl;
    }else{
        cout << "False" << endl;
    }

    return 0;
}