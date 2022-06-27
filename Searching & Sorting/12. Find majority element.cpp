// https://www.geeksforgeeks.org/majority-element/

// Method - 1 (O(n^2))
// Method - 2(TC: O(n) & SC: O(n)),
// Method - 3(O(nlogn))
// Bruteforce, HashMap, Sorting

// Method - 4
//  Boyer-Moore Voting Algorithm

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int cnt = 0;
        int mj = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (cnt == 0)
                mj = nums[i];
            if (mj == nums[i])
                cnt++;
            else
                cnt--;
        }
        return mj;
    }
};

// TestCase -> {7, 7, 5, 7, 5, 1, 5, 7, 5, 5, 7, 7, 5, 5, 5, 5}