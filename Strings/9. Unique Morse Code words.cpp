// https://leetcode.com/problems/unique-morse-code-words/

class Solution
{
public:
    int uniqueMorseRepresentations(vector<string> &words)
    {
        string code[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
                           "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-",
                           ".--", "-..-", "-.--", "--.."};
        set<string> s;
        string temp = "";
        for (int i = 0; i < words.size(); i++)
        {
            temp = "";
            for (int j = 0; j < words[i].size(); j++)
            {
                temp += code[words[i][j] - 'a'];
            }
            s.insert(temp);
        }
        return s.size();
    }
};

