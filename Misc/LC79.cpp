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

bool dfs(vector<vector<char>> &board, string word, int i, int j, int count)
{
    if (count == word.size())
    {
        return true;
    }

    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || word[count] != board[i][j])
    {
        return false;
    }

    char temp = board[i][j];
    board[i][j] = '*';

    bool isfound = dfs(board, word, i + 1, j, count + 1) || dfs(board, word, i - 1, j, count + 1) || dfs(board, word, i, j + 1, count + 1) || dfs(board, word, i, j - 1, count + 1);

    board[i][j] = temp;
    return isfound;
}

bool exist(vector<vector<char>> &board, string word)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == word[0] && dfs(board, word, i, j, 0))
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    string word = "ABCCED";

    cout << (exist(board, word) ? "true" : "false") << endl;

    return 0;
}