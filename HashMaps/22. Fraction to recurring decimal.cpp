/// https://leetcode.com/problems/fraction-to-recurring-decimal/

class Solution
{
public:
    string fractionToDecimal(int64_t n, int64_t d)
    {     
        string res = "";
        if ((n < 0 and d > 0) or (n > 0 and d < 0))
            res += "-";
        
        n = abs(n);
        d = abs(d);

        if (n % d == 0)
            return res + to_string(n / d);

        map<int, int> m;

        res += to_string(n / d) + '.';
        long long rem = n % d;
        while (rem)
        {
            if (m[rem])
            {
                res.insert(m[rem], "(");
                res += ')';
                return res;
            }
            else
            {
                m[rem] = res.size();
                rem *= 10;
                int q = rem / d;
                res += to_string(q);
                rem = rem % d;
            }
        }

        return res;
    }
};