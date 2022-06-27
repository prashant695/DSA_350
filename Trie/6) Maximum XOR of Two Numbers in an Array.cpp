// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

// Method 1 (bruteforce)

// Time Complexity: O(n^2)
// SPace Complexity : O(1)

// Method 2 (Trie)
// Time Complexity: O(n*32)
// Space Complexity : O(2*32)

class Trie
{
public:
    /** Initialize your data structure here. */

    Trie *children[2] = {};
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
            if (node->children[word[i] - '0'] == NULL)
                node->children[word[i] - '0'] = new Trie();
            node = node->children[word[i] - '0'];
        }
        node->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    int search(string word)
    {
        Trie *node = this;
        int k = 31;
        int sum = 0;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->children[!(word[i] - '0')])
            {
                sum += pow(2, k);
                node = node->children[!(word[i] - '0')];
            }
            else if (node->children[(word[i] - '0')])
                node = node->children[(word[i] - '0')];
            else
                return sum;

            k--;
        }
        return sum;
    }
};
class Solution
{
public:
    string decimal_to_binary(int x)
    {
        string res = "";
        while (x)
        {
            if (x % 2 == 1)
                res += '1';
            else
                res += '0';
            x /= 2;
        }
        for (int i = res.size(); i < 32; i++)
        {
            res += '0';
        }
        reverse(res.begin(), res.end());
        return res;
    }
    int findMaximumXOR(vector<int> &nums)
    {

        Trie *obj = new Trie();
        for (auto x : nums)
        {
            string binary = bitset<32>(x).to_string();
            obj->insert(binary);
        }
        int ma = 0;
        for (auto x : nums)
        {
            string binary = bitset<32>(x).to_string();
            int val = obj->search(binary);
            ma = max(ma, val);
        }

        return ma;
    }
};