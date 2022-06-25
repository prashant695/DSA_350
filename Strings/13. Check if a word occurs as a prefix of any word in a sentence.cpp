// https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/

// Using StringStream
class Solution
{
public:
    int isPrefixOfWord(string sentence, string searchWord)
    {
        stringstream ss(sentence);
        string word;
        int cnt = 0;

        while (ss >> word)
        {
            cnt++;
            if (word.size() >= searchWord.size())
            {
                if (word.substr(0, searchWord.size()) == searchWord)
                    return cnt;
            }
        }
        return -1;
    }
};