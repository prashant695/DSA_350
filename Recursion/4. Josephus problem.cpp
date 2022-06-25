// https://leetcode.com/problems/find-the-winner-of-the-circular-game/

// Method - 1
// Time -> O(n) space -> O(n)
class Solution
{
public:
    int winner(int n, int k)
    {
        if (n == 1)
            return 0;
        return (winner(n - 1, k) + k) % n;
    }
    int findTheWinner(int n, int k)
    {
        return winner(n, k) + 1;
    }
};

// Method - 2
// Time -> O(n) space -> O(1)
class Solution
{
public:
    int winner(int n, int k)
    {
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans = (ans + k) % i;
        }
        return ans;
    }
    int findTheWinner(int n, int k)
    {
        return winner(n, k) + 1;
    }
};
