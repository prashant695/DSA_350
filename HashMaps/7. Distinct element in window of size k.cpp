// https://practice.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1

// Method - 1
// Bruteforce
// Time -> O(n2)

// Method - 2
// Sliding window and Hashmap
// Time -> O(n) Space -> O(n)

class Solution
{
public:
    vector<int> countDistinct(int arr[], int n, int k)
    {
        vector<int> v;
        unordered_map<int, int> m;

        int cnt = 0;

        for (int i = 0; i < k; i++)
        {
            if (m[arr[i]] == 0)
                cnt++;
            m[arr[i]] += 1;
        }

        v.push_back(cnt);

        for (int i = k; i < n; i++)
        {

            if (m[arr[i - k]] == 1)
                cnt--;

            if (m[arr[i]] == 0)
                cnt++;

            m[arr[i - k]] -= 1;
            m[arr[i]] += 1;

            v.push_back(cnt);
        }
        return v;
    }
};