// Method - 1
// Merge both the sorted arrays
// Time -> O(n+m)  Space -> O(n+m)

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> v;
        int i = 0, j = 0;
        while (i < nums1.size() and j < nums2.size())
        {
            if (nums1[i] < nums2[j])
                v.push_back(nums1[i++]);
            else
                v.push_back(nums2[j++]);
        }

        while (i < nums1.size())
            v.push_back(nums1[i++]);

        while (j < nums2.size())
            v.push_back(nums2[j++]);

        if (v.size() % 2)
            return v[v.size() / 2];
        return (v[v.size() / 2] + v[v.size() / 2 - 1]) / 2.0;
    }
};

// Method - 2 (Optmised Method-1)
// Merge the both sorted array, Instead of storing all the elements keep a record of the middle element
// Time -> O(n+m)  Space -> O(1)

// Method - 3
// TC: O(min(log m, log n)) Since binary search is applied
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums2.size() < nums1.size())
            return findMedianSortedArrays(nums2, nums1);

        int n1 = nums1.size(), n2 = nums2.size(), l = 0, h = n1;
        int c1, c2, l1, l2, r1, r2;

        while (l <= h)
        {
            c1 = (l + h) / 2;
            c2 = (n1 + n2 + 1) / 2 - c1;

            if (c1 == 0)
                l1 = INT_MIN;
            else
                l1 = nums1[c1 - 1];

            if (c2 == 0)
                l2 = INT_MIN;
            else
                l2 = nums2[c2 - 1];

            if (c1 == n1)
                r1 = INT_MAX;
            else
                r1 = nums1[c1];

            if (c2 == n2)
                r2 = INT_MAX;
            else
                r2 = nums2[c2];

            if (l1 <= r2 && l2 <= r1)
            {
                if ((n1 + n2) % 2 == 0)
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                else
                    return max(l1, l2);
            }
            else if (l1 > r2)
            {
                h = c1 - 1;
            }
            else
            {
                l = c1 + 1;
            }
        }
        return 0.0;
    }
};