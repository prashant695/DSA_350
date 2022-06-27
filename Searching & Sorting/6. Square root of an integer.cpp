// https://leetcode.com/problems/sqrtx/

class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0)
            return 0;
        int l = 1, r = x, ans, mid;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (mid <= x / mid)
            // Is equivalent to mid * mid == x,
            // however the above written statement may lead to integer overflow
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        return ans;
    }
};

// N = 10    ans = 3

// l    r    mid
// 1    10    5    5^2 > 10
// 1    4     2    2^2 < 10
// 3    4     3    3^2 < 10
// 4    4     4    4^2 > 10
// 4    3     -

// For finding Nth root of the number
// if(multiply(mid, n) <= x)