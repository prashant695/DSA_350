// https://practice.geeksforgeeks.org/problems/activity-selection-1587115620/1/

class Solution
{
public:
    // Function to find the maximum number of activities that can
    // be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<vector<int>> intervals;
        for (int i = 0; i < n; i++)
        {
            intervals.push_back({start[i], end[i]});
        }
        sort(intervals.begin(), intervals.end());
        int cnt = 1;
        int left = 0;
        int right = 1;
        while (right < intervals.size())
        {
            if (intervals[left][1] < intervals[right][0])
            {
                left = right;
                right++;
                cnt++;
            }
            else if (intervals[left][1] < intervals[right][1])
            {
                right++;
            }
            else
            {
                left = right;
                right++;
            }
        }
        return cnt;
    }
};