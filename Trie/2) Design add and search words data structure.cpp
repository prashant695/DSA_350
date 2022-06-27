// https://leetcode.com/problems/design-add-and-search-words-data-structure/

// Time Complexity : O(n * m) m-> maximum word length
// Space Complexity : O(26*n) n->maximum word length

class WordDictionary
{
public:
    vector<WordDictionary *> children;
    bool isEnd;
    WordDictionary()
    {
        isEnd = false;
        children = vector<WordDictionary *>(26, nullptr);
    }

    void addWord(string word)
    {
        WordDictionary *node = this;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->children[word[i] - 'a'] == NULL)
                node->children[word[i] - 'a'] = new WordDictionary();
            node = node->children[word[i] - 'a'];
        }
        node->isEnd = true;
    }

    bool search(string word)
    {
        WordDictionary *node = this;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node)
                return false;
            if (word[i] == '.')
            {
                for (auto x : node->children)
                    if (x and x->search(word.substr(i + 1)))
                        return true;
                return false;
            }
            if (node->children[word[i] - 'a'] == NULL)
                return false;
            node = node->children[word[i] - 'a'];
        }
        return node->isEnd;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */