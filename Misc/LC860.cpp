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

bool lemonadeChange(vector<int> &bills)
{
    int five = 0;
    int ten = 0;

    for (int i = 0; i < bills.size(); i++)
    {
        if (bills[i] == 5)
        {
            five++;
        }
        else if (bills[i] == 10)
        {
            five--;
            ten++;
            if (five < 0)
            {
                return false;
            }
        }
        else
        {
            if (bills[i] == 20)
            {
                if (five > 0 && ten > 0)
                {
                    five--;
                    ten--;
                }
                else if (five >= 3)
                {
                    five -= 3;
                }
                else
                {
                    return false;
                }
            }
        }
    }

    return true;
}

int main()
{
    vector<int> bills = {5, 5, 5, 10, 20};

    bool ans = lemonadeChange(bills);

    if (ans)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}