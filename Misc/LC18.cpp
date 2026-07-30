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

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    if (nums.size() < 4)
    {
        return {};
    }

    for (int i = 0; i < nums.size() - 3; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        for (int j = i + 1; j < nums.size() - 2; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
            {
                continue;
            }

            int left = j + 1;
            int right = nums.size() - 1;

            while (left < right)
            {
                long long int sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                vector<int> part = {nums[i], nums[j], nums[left], nums[right]};

                if (sum < target)
                {
                    left++;
                }
                else if (sum > target)
                {
                    right--;
                }
                else
                {
                    ans.push_back(part);
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1])
                    {
                        left++;
                    }

                    while (left < right && nums[right] == nums[right + 1])
                    {
                        right--;
                    }
                }
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {-2, -1, -1, 1, 1, 2, 2};
    int target = 0;

    vector<vector<int>> ans = fourSum(nums, target);

    for(auto &quad : ans)
    {
        for(int x : quad)
            cout << x << " ";

        cout << endl;
    }

    return 0;
}