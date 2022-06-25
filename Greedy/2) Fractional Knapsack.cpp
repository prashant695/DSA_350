// https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1/

class Solution
{
public:
    bool static cmp(pair<int, int> v1, pair<int, int> v2)
    {
        return (v1.first / (1.0 * v1.second)) > (v2.first / (1.0 * v2.second));
    }
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
            v.push_back({arr[i].value, arr[i].weight});

        sort(v.begin(), v.end(), cmp);
        double cnt = 0;
        int i = 0;

        while (W > 0 and i < n)
        {
            if (W >= v[i].second)
            {
                cnt += v[i].first;
                W -= v[i].second;
            }
            else
            {
                cnt += (v[i].first / (1.0 * v[i].second)) * W;
                break;
            }
            i++;
        }
        return cnt;
    }
};