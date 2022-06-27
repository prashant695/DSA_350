// https://leetcode.com/problems/replace-words/

// Time Complexity : O(n * m) m-> maximum word length
// Space Complexity : O(26*n) n->maximum word length

class Trie
{
public:
    /** Initialize your data structure here. */

    Trie *children[26] = {};
    bool isEnd;
    Trie()
    {
        isEnd = false;
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Trie *node = this;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->children[word[i] - 'a'] == NULL)
                node->children[word[i] - 'a'] = new Trie();
            node = node->children[word[i] - 'a'];
        }
        node->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    string search(string word)
    {
        Trie *node = this;
        string w;
        for (int i = 0; i < word.size(); i++)
        {
            w += word[i];
            if (node->children[word[i] - 'a'] == NULL)
                return "";
            node = node->children[word[i] - 'a'];
            if (node->isEnd == true)
                return w;
        }
        return "";
    }
};

class Solution
{
public:
    string replaceWords(vector<string> &d, string s)
    {

        Trie *obj = new Trie();
        for (auto x : d)
        {
            obj->insert(x);
        }
        string word;
        string res;
        stringstream ob(s);
        while (ob >> word)
        {
            string a = obj->search(word);
            if (a.size() != 0)
                res += a;
            else
                res += word;

            res += " ";
        }

        return res.substr(0, res.size() - 1);
    }
};