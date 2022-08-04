// https://leetcode.com/problems/word-ladder/

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        queue<string> q;
        int cnt = 0;
        map<string, int> m;

        for (auto x : wordList)
            m[x] = 1;

        q.push(beginWord);

        while (q.empty() == false)
        {
            int qu = q.size();
            cnt++;
            for (int i = 0; i < qu; i++)
            {
                string tmp = q.front();
                q.pop();
                if (tmp == endWord)
                    return cnt;

                for (int j = 0; j < tmp.size(); j++)
                {
                    string x = tmp;
                    for (int k = 0; k < 26; k++)
                    {
                        tmp[j] = k + 'a';
                        if (m.find(tmp) != m.end())
                        {
                            q.push(tmp);
                            m.erase(tmp);
                        }
                    }

                    tmp = x;
                }
            }
        }
        return 0;
    }
};