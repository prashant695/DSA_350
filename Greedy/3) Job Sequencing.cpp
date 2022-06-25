// https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#
/*
struct Job
{
    int id;	 // Job Id
    int dead; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
*/
// d's ->deadline maximum value
// Time Complexity : O(n*d+nlogn)
// Space Complexity : O(d)

class Solution
{
public:
    // Function to find the maximum profit and the number of jobs done.
    static bool cmp(Job obj1, Job obj2)
    {
        if (obj1.profit == obj2.profit)
            return obj1.dead < obj2.dead;
        else
            return obj1.profit > obj2.profit;
    }
    vector<int> JobScheduling(Job arr[], int n)
    {
        sort(arr, arr + n, cmp);
        int cnt = 0, sum = 0;

        int d[102] = {false};
        for (int i = 0; i < n; i++)
        {
            for (int j = arr[i].dead - 1; j >= 0; j--)
            {
                if (d[j] == 0)
                {
                    d[j] = 1;
                    cnt++;
                    sum += arr[i].profit;
                    break;
                }
            }
        }

        return {cnt, sum};
    }
};