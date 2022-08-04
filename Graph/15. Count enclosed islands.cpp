// https://leetcode.com/problems/number-of-closed-islands/

class Solution
{
public:
    void dfs(vector<vector<int>> &board, int i, int j)
    {
        int r = board.size();
        int c = board[0].size();
        if (i < 0 or j < 0 or i >= r or j >= c or vis[i][j] or board[i][j] != 0)
            return;

        board[i][j] = 1;
        dfs(board, i + 1, j);
        dfs(board, i - 1, j);
        dfs(board, i, j + 1);
        dfs(board, i, j - 1);
    }
    int closedIsland(vector<vector<int>> &board)
    {
        int cnt = 0;
        int r = board.size();
        int c = board[0].size();

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if ((i == 0 or j == 0 or i == r - 1 or j == c - 1) and (board[i][j] == 0))
                    dfs(board, i, j);
            }
        }
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (board[i][j] == 0)
                {
                    cnt++;
                    dfs(board, i, j);
                }
            }
        }
        return cnt;
    }
};