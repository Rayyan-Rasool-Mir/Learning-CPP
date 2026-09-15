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

bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2)
{
    return max(rec1[0], rec2[0]) < min(rec1[2], rec2[2]) && max(rec1[1], rec2[1]) < min(rec1[3], rec2[3]);
}

int main()
{
    vector<int> rec1 = {0, 0, 2, 2};
    vector<int> rec2 = {1, 1, 3, 3};

    vector<int> rec3 = {0, 0, 2, 2};
    vector<int> rec4 = {2, 0, 4, 2};

    vector<int> rec5 = {0, 0, 1, 1};
    vector<int> rec6 = {2, 2, 3, 3};

    cout << boolalpha << isRectangleOverlap(rec1, rec2) << endl; // 1
    cout << boolalpha << isRectangleOverlap(rec3, rec4) << endl; // 0
    cout << boolalpha << isRectangleOverlap(rec5, rec6) << endl; // 0

    return 0;
}