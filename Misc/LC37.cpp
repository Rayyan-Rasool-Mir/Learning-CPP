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

bool issafe(vector<vector<char>> &board, int row, int col, char dig)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == dig)
        {
            return false;
        }
    }

    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == dig)
        {
            return false;
        }
    }
    int sr = (row / 3) * 3;
    int sc = (col / 3) * 3;

    for (int i = sr; i < sr + 3; i++)
    {
        for (int j = sc; j < sc + 3; j++)
        {
            if (board[i][j] == dig)
            {
                return false;
            }
        }
    }

    return true;
}

bool help(vector<vector<char>> &board, int row, int col)
{
    if (row == 9)
    {
        return true;
    }

    int nextrow = row, nextcol = col + 1;
    if (nextcol == 9)
    {
        nextrow = row + 1;
        nextcol = 0;
    }
    if (board[row][col] != '.')
    {
        return help(board, nextrow, nextcol);
    }

    for (char i = '1'; i <= '9'; i++)
    {
        if (issafe(board, row, col, i))
        {
            board[row][col] = i;
            if (help(board, nextrow, nextcol))
            {
                return true;
            }
            board[row][col] = '.';
        }
    }
    return false;
}

void solveSudoku(vector<vector<char>> &board)
{
    help(board, 0, 0);
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

    solveSudoku(board);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}