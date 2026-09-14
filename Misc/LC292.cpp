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

bool canWinNim(int n)
{
    return n % 4 != 0;
}

int main()
{
    cout << boolalpha<< canWinNim(1) << endl;  // 1
    cout << boolalpha<< canWinNim(4) << endl;  // 0
    cout << boolalpha<< canWinNim(7) << endl;  // 1
    cout << boolalpha<< canWinNim(8) << endl;  // 0
    cout << boolalpha<< canWinNim(10) << endl; // 1

    return 0;
}