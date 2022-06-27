// https://leetcode.com/problems/prefix-and-suffix-search/

// TRIE Solution

class Trie
{
public:
    Trie *children[27] = {};
    bool isEnd;
    int index;
    Trie()
    {
        isEnd = false;
        index = 0;
    }

    void insert(string word, int index)
    {
        Trie *node = this;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->children[word[i] - '`'] == NULL)
                node->children[word[i] - '`'] = new Trie();
            node = node->children[word[i] - '`'];
            node->index = index;
        }
        node->isEnd = true;
    }

    int startsWith(string prefix)
    {
        Trie *node = this;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (node->children[prefix[i] - '`'] == NULL)
                return -1;
            node = node->children[prefix[i] - '`'];
        }
        return node->index;
    }
};

class WordFilter
{
public:
    Trie root;
    WordFilter(vector<string> &words)
    {
        for (int i = 0; i < words.size(); i++)
        {
            string tmp = '`' + words[i];
            for (int j = words[i].size() - 1; j >= 0; j--)
            {
                string newstring = words[i][j] + tmp;
                tmp = newstring;
                root.insert(newstring, i);
            }
        }
    }

    int f(string prefix, string suffix)
    {
        string word = suffix + '`' + prefix;
        return root.startsWith(word);
    }
};



// MAP Solution
class WordFilter
{
public:
    map<string, int> mp;
    WordFilter(vector<string> &words)
    {
        int k = 0;
        for (auto x : words)
        {
            for (int i = 0; i <= x.size(); i++)
            {
                for (int j = 0; j <= x.size(); j++)
                {
                    mp[x.substr(0, i) + "#" + x.substr(j, x.size())] = k + 1;
                }
            }
            k++;
        }
    }

    int f(string prefix, string suffix)
    {
        if (mp[prefix + "#" + suffix] > 0)
            return mp[prefix + "#" + suffix] - 1;
        else
            return -1;
    }
};
