// https://leetcode.com/problems/word-search/

class Solution
{
public:
    bool help(vector<vector<char>> &board, const string &word, string res, int i, int j, int x)
    {
        if (res == word)
            return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || x >= word.size())
            return false;
        if (board[i][j] == '#' || board[i][j] != word[x])
            return false;

        char t = board[i][j];
        board[i][j] = '#';
        bool tt = help(board, word, res + t, i + 1, j, x + 1) || help(board, word, res + t, i - 1, j, x + 1) || help(board, word, res + t, i, j + 1, x + 1) || help(board, word, res + t, i, j - 1, x + 1);

        board[i][j] = t;
        return tt;
    }

    bool exist(vector<vector<char>> &board, string word)
    {

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == word[0])
                    if (help(board, word, "", i, j, 0))
                        return true;
            }
        }
        return false;
    }
};
