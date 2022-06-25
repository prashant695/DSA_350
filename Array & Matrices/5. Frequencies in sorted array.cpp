// Method - 1
// HashMap
// Time complexity o(n)
// Space Complexity o(n)

// Method - 2
class Solution
{
public:
    void printfreq(vector<int> &arr, int n)
    {
        int cnt = 1;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] == arr[i - 1])
                cnt++;
            else
            {
                cout << "Frequency of " << arr[i - 1] << " is " << cnt << endl;
                cnt = 1;
            }
        }
        cout << "Frequency of " << arr[n - 1] << " is " << cnt << endl;
    }
};