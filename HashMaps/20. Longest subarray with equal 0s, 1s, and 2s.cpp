/// 1  1  2  0  1  0  1  2  1  2  2  0  1
// ---------x0
// ---------x1
// ---------x2

// ---------------------------------x0'
// ---------------------------------x1'
// ---------------------------------x2'

// Let x0, x1, x2 be number of 0, 1, 2 upto index 3
// Let x0', x1', x2' be number of 0, 1, 2 upto index 7

// If the subarray in between have equal number of 0, 1, 2
// then
// x1-x0 = x1'-x0'
// x2-x1 = x2'-x1'

class Solution
{
public:
    long long getSubstringWithEqual012(string s)
    {
        int z = 0, o = 0, t = 0, len = 0, n = s.size();
        unordered_map<pair<int, int>, int> first_occ;

        first_occ[{0, 0}] = -1;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
                z++;
            else if (s[i] == '1')
                o++;
            else
                t++;

            if (first_occ.count([ {t - o, o - z} ]) == 0)
                first_occ[{t - o, o - z}] = i;

            len = max(len, i - first_occ[{t - o, o - z}]);
        }
        return len;
    }
};
