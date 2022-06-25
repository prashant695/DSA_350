
// O(2n)
class Solution
{
public:
    vector<int> minmax(vector<int> &v)
    {
        vector<int> v;
        int minn = v[0], maxx = v[0];

        for (int i = 1; i < v.size(); i++)
        {
            maxx = max(maxx, v[i]);
        }

        for (int i = 1; i < v.size(); i++)
        {
            minn = min(minn, v[i]);
        }
        v.push_back({maxx, minn});
        return v;
    }
};

// WorstCase - O(2n-1)
// BestCase - O(n-1)
class Solution
{
public:
    vector<int> minmax(vector<int> &v)
    {
        vector<int> v;
        int minn = v[0], maxx = v[0];

        for (int i = 1; i < v.size(); i++)
        {
            if (v[i] > maxx)
                maxx = v[i];
            else if (v[i] < minn)
                minn = v[i];
        }

        v.push_back({maxx, minn});
        return v;
    }
};

// Pair of elements
// Number of comparisons - O(3n/2)
class Solution
{
public:
    vector<int> minmax(vector<int> &v)
    {
        int maxx, minn, i = 0, n = v.size();

        maxx = v[0];
        minn = v[0];
        i++;
        // When n = odd

        if (v[1] > v[0])
        {
            maxx = v[1];
            minn = v[0];
        }

        else
        {
            maxx = v[0];
            minn = v[1];
        }
        i += 2;
        // When n = even

        while (i < n)
        {
            if (v[i] > v[i + 1])
            {
                maxx = max(maxx, v[i]);
                minn = min(minn, v[i + 1]);
            }
            else
            {
                maxx = max(maxx, v[i + 1]);
                minn = min(minn, v[i]);
            }

            i += 2;
        }
    }
};
