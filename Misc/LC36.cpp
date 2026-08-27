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

bool isValidSudoku(vector<vector<char>> &board)
{
    vector<vector<int>> rows(9, vector<int>(9, 0));
    vector<vector<int>> cols(9, vector<int>(9, 0));
    vector<vector<int>> boxes(9, vector<int>(9, 0));

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == '.')
            {
                continue;
            }

            int digit = board[i][j] - '1';
            int box = (i / 3) * 3 + (j / 3);

            if (rows[i][digit] == 1 || cols[j][digit] == 1 || boxes[box][digit] == 1)
            {
                return false;
            }

            rows[i][digit] = 1;
            cols[j][digit] = 1;
            boxes[box][digit] = 1;
        }
    }

    return true;
}

int main()
{
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    cout << boolalpha<< isValidSudoku(board) << endl;

    return 0;
}