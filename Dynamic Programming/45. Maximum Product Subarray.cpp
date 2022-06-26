// https://leetcode.com/problems/maximum-product-subarray/

class Solution
{
public:
    // Why from both sides
    //[-1,-2,-3]

    // Case 1: All positive
    // Result: Product of all elements

    // Case 2: All positive and 1 zero
    // Result: Product of elements before or after 0
    // At zero we consider the prefixProd built till now and reset counter to 1 for the next element

    // Case 3: All positive and more than 1 zero
    // Result: Product of elements before or after 0 or in between two zeroes
    // Can be handled with above case

    // Case 4: Even negatives
    // Result: Product of all elements

    // Case 5: Odd negative
    // Result: Consider from starting to element before last negative or ending to element after first negative

    // 9 -8 7 3 -5 -8 -1 -2 3
    // {9 -8 7 3 -5 -8 -1} -2 3
    // or
    // 9 -8 {7 3 -5 -8 -1 -2 3}

    // By analysing these cases I came up with above solution. Hope it helps.
    int maxProduct(vector<int> &nums)
    {
        int pro = 1;
        int ma = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            pro = pro * nums[i];
            ma = max(ma, pro);
            if (pro == 0)
                pro = 1;
        }
        pro = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            pro = pro * nums[i];
            ma = max(ma, pro);
            if (pro == 0)
                pro = 1;
        }
        return ma;
    }
};