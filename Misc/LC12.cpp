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

string intToRoman(int num)
{
    vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    string ans = "";

    for (int i = 0; i < values.size(); i++)
    {
        while (num >= values[i])
        {
            ans += symbols[i];
            num -= values[i];
        }
    }
    return ans;
}

int main()
{
    cout << intToRoman(3749) << endl;  // MMMCDXLIX
    cout << intToRoman(1994) << endl;  // MCMXCIV
    cout << intToRoman(58) << endl;    // LVIII
    cout << intToRoman(9) << endl;     // IX

    return 0;
}