

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        // When the customer gives us $20, we have two options:

        // To give three $5 in return.
        // To give one $5 and one $10.
        // On insight is that the second option (if possible) is always better than the first one.
        // Because two $5 in hand is always better than one $10.

        int five = 0, ten = 0, twinty = 0;

        for (int i = 0; i < bills.size(); i++)
        {
            if (bills[i] == 5)
                five++;
            else if (bills[i] == 10)
                ten++, five--;
            else if (ten)
                ten--, five--;
            else
                five -= 3;

            if (five < 0)
                return 0;
        }

        return 1;
    }
};