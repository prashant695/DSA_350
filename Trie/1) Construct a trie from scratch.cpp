// https://leetcode.com/problems/implement-trie-prefix-tree/

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
    // Time Complexity : O(n) n->word length
    // Space Complexity : O(26*n) n-> word length
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
    // Time Complexity : O(n) n->word length
    // Space Complexity : O(1)
    bool search(string word)
    {
        Trie *node = this;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->children[word[i] - 'a'] == NULL)
                return false;
            node = node->children[word[i] - 'a'];
        }
        return node->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    // Time Complexity : O(n) n->word length
    // Space Complexity : O(1)
    bool startsWith(string prefix)
    {
        Trie *node = this;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (node->children[prefix[i] - 'a'] == NULL)
                return false;
            node = node->children[prefix[i] - 'a'];
        }
        return true;
    }
};




//  STRIVER Solution
#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define endl "\n"
#define MAXN 100001
#define INF 1e18 + 1
struct Node
{
    Node *links[26];
    bool flag = false;
    // checks if the reference trie is present or not
    bool containKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
    // creating reference trie
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    // to get the next node for traversal
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    // setting flag to true at the end of the word
    void setEnd()
    {
        flag = true;
    }
    // checking if the word is completed or not
    bool isEnd()
    {
        return flag;
    }
};
class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        // creating new obejct
        root = new Node();
    }

    void insert(string word)
    {
        // initializing dummy node pointing to root initially
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            // moves to reference trie
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containKey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix)
    {
        Node *node = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (!node->containKey(prefix[i]))
            {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};

int main()
{
    int n = 5;
    vector<int> type = {1, 1, 2, 3, 2};
    vector<string> value = {"hello", "help", "help", "hel", "hel"};
    Trie trie;
    for (int i = 0; i < n; i++)
    {
        if (type[i] == 1)
        {
            trie.insert(value[i]);
        }
        else if (type[i] == 2)
        {
            if (trie.search(value[i]))
            {
                cout << "true"
                     << "\n";
            }
            else
            {
                cout << "false"
                     << "\n";
            }
        }
        else
        {
            if (trie.startsWith(value[i]))
            {
                cout << "true"
                     << "\n";
            }
            else
            {
                cout << "false"
                     << "\n";
            }
        }
    }
}