// https://leetcode.com/problems/knight-probability-in-chessboard/

class Solution
{
public:
    double dp[102][26][26];
    double dfs(int n, int k, int x, int y)
    {
        if (x < 0 or y < 0 or x >= n or y >= n)
            return 0;

        if (dp[k][x][y] >= 0)
            return dp[k][x][y];

        if (k == 0)
        {
            if (x >= 0 and y >= 0 and x < n and y < n)
                return 1;
            return 0;
        }

        double tot = dfs(n, k - 1, x + 2, y - 1) + dfs(n, k - 1, x + 2, y + 1) + dfs(n, k - 1, x - 2, y - 1) + dfs(n, k - 1, x - 2, y + 1) + dfs(n, k - 1, x + 1, y + 2) + dfs(n, k - 1, x + 1, y - 2) + dfs(n, k - 1, x - 1, y + 2) + dfs(n, k - 1, x - 1, y - 2);

        float res = tot / 8;
        dp[k][x][y] = res;
        return res;
    }
    double knightProbability(int n, int k, int x, int y)
    {
        memset(dp, -1, sizeof dp);

        double xx = dfs(n, k, x, y);
        return xx;
    }
};

// https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1/#
class Solution
{
public:
    bool isValid(int x, int y, int N)
    {
        if (x >= 0 && x < N && y >= 0 && y < N)
            return true;
        return false;
    }
    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
    {
        int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
        int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};
        int cnt = 0;

        vector<vector<bool>> visited(N, vector<bool>(N, false));
        queue<pair<int, int>> q;

        q.push(make_pair(KnightPos[0] - 1, KnightPos[1] - 1));

        visited[KnightPos[0] - 1][KnightPos[1] - 1] = true;

        while (!q.empty())
        {
            cnt++;
            int qu = q.size();
            for (int j = 0; j < qu; j++)
            {
                pair<int, int> currCell = q.front();
                q.pop();

                for (int i = 0; i < 8; i++)
                {
                    int x = currCell.first + dx[i];
                    int y = currCell.second + dy[i];

                    if (currCell.first == TargetPos[0] - 1 && currCell.second == TargetPos[1] - 1)
                        return cnt - 1;

                    if (isValid(x, y, N) && !visited[x][y])
                    {
                        q.push(make_pair(x, y));
                        visited[x][y] = true;
                    }
                }
            }
        }
        return -1;
    }
};