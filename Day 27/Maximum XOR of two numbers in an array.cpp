// Time Complexity: O(N*32)
// Space Complexity: O(N*32)

#include <bits/stdc++.h>

struct Node
{

    Node *child[2];

    bool contains(int bit) { return child[bit] != NULL; }

    Node *get(int bit) { return child[bit]; }

    Node *put(int bit, Node *node) { child[bit] = node; }
};

class Trie
{

public:
    Node *root;

    Trie() { root = new Node(); }

    void insert(int num)
    {

        Node *node = root;

        for (int i = 31; i >= 0; i--)
        {

            int bit = (num >> i) & 1;

            if (!node->contains(bit))
            {

                node->put(bit, new Node());
            }

            node = node->get(bit);
        }
    }

    int getmax(int num)
    {

        Node *node = root;

        int maxnum = 0;

        for (int i = 31; i >= 0; i--)
        {

            int bit = (num >> i) & 1;

            if (node->contains(1 - bit))
            {

                maxnum = (1 << i) | maxnum;

                node = node->get(1 - bit);
            }
            else
            {

                node = node->get(bit);
            }
        }

        return maxnum;
    }
};

int maximumXor(vector<int> A)
{

    // Write your code here.

    Trie trie;

    for (auto it : A)
    {

        trie.insert(it);
    }

    int maxi = 0;

    for (auto it : A)
    {

        maxi = max(maxi, trie.getmax(it));
    }

    return maxi;
}