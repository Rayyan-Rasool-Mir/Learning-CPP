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

string digitSum(string s, int k)
{
    while (s.size() > k)
    {
        string temp = "";

        for (int i = 0; i < s.size(); i += k)
        {
            int sum = 0;
            for (int j = i; j < min(i + k, (int)s.size()); j++)
            {
                sum += s[j] - '0';
            }
            temp += to_string(sum);
        }
        s = temp;
    }

    return s;
}

int main()
{
    string s = "11111222223";
    int k = 3;
    string result = digitSum(s, k);
    cout << "Result: " << result << endl;
    return 0;
}