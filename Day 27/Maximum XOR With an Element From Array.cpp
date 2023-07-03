// Time Complexity:O(M) + O(MlogM) + O(M*32 + N*32)   "M" Size of Vector of OfflineQueries
// Space Complexity:O(32*N)

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

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries)
{
    //	Write your coode here.
    vector<int> ans(queries.size(), 0);
    vector<pair<int, pair<int, int>>> offlineQueries;
    sort(arr.begin(), arr.end());
    int index = 0;
    for (auto &it : queries)
    {
        offlineQueries.push_back({it[1],
                                  {it[0],
                                   index++}});
    }
    sort(offlineQueries.begin(), offlineQueries.end());
    int i = 0;
    int n = arr.size();
    Trie trie;

    for (auto &it : offlineQueries)
    {
        while (i < n && arr[i] <= it.first)
        {
            trie.insert(arr[i]);
            i++;
        }
        if (i != 0)
            ans[it.second.second] = trie.getmax(it.second.first);
        else
            ans[it.second.second] = -1;
    }
    return ans;
}