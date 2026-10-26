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

int total(string date)
{
    int month = stoi(date.substr(0, 2));
    int day = stoi(date.substr(3, 2));

    int arr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int total = day;

    for (int i = 0; i < month - 1; i++)
    {
        total += arr[i];
    }

    return total;
}

int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob)
{
    int stAl = total(arriveAlice);
    int stBob = total(arriveBob);
    int endAl = total(leaveAlice);
    int endBob = total(leaveBob);

    int start = max(stAl, stBob);
    int end = min(endAl, endBob);

    if (end < start)
    {
        return 0;
    }

    return end - start + 1;
}

int main()
{
    string arriveAlice = "08-15";
    string leaveAlice = "08-18";
    string arriveBob = "08-16";
    string leaveBob = "08-19";
    int result = countDaysTogether(arriveAlice, leaveAlice, arriveBob, leaveBob);
    cout << "Total days together: " << result << endl;
    
    return 0;
}