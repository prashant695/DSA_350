// https://leetcode.com/problems/most-common-word/

class Solution
{
public:
    string mostCommonWord(string para, vector<string> &banned)
    {
        unordered_map<string, int> m;
        string word, ans;
        int maxx = -1;

        for (int i = 0; i < para.size(); i++)
            if (isalpha(para[i]))
                para[i] = tolower(para[i]);
            else
                para[i] = ' ';

        for (int i = 0; i < banned.size(); i++)
            m[banned[i]] = -1;

        stringstream ss(para);
        while (ss >> word)
        {
            if (m[word] >= 0 and ++m[word] > maxx)
            {
                maxx = m[word];
                ans = word;
            }
        }
        return ans;
    }
};