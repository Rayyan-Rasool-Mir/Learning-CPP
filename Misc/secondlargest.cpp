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
//find the second largest element in an array w/o sorting in O(n) TC
int main()
{
    int arr[4] = {10, 9, 8, 7};
    int largest = 0;
    int secondlargest = 0;

    for (int i = 0; i < 4; i++)
    {
        if (largest < arr[i])
        {
            secondlargest = largest;
            largest = arr[i];
        }else if (secondlargest <arr[i])
        {
            secondlargest = arr[i];
        }
        
    }

    cout << largest<<endl;;
    cout << secondlargest<<endl;;

    return 0;
}