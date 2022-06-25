// https://leetcode.com/problems/robot-return-to-origin/

// Robot initially is at (0, 0)
// After performing certain moves state whether is it at origin again?

class Solution
{
public:
    bool judgeCircle(string moves)
    {
        int x = 0, y = 0;
        for (int i = 0; i < moves.size(); i++)
        {
            if (moves[i] == 'U')
                y++;
            else if (moves[i] == 'D')
                y--;
            else if (moves[i] == 'R')
                x++;
            else if (moves[i] == 'L')
                x--;
        }
        return (x == 0 && y == 0);
    }
};