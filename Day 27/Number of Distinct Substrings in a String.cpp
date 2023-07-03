// Time Complexity: O(N^2)
// Space Complexity: O(N^2)

#include <bits/stdc++.h>
struct Node
{
    Node *links[26];

    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
};

int distinctSubstring(string &word)
{
    //  Write your code here.
    Node *root = new Node();
    int count = 0;
    int n = word.size();
    for (int i = 0; i < n; i++)
    {
        Node *node = root;

        for (int j = i; j < n; j++)
        {
            if (!node->containsKey(word[j]))
            {
                node->put(word[j], new Node());
                count++;
            }
            node = node->get(word[j]);
        }
    }
    return count;
}
