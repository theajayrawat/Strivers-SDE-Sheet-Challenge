// Time Complexity : O(V+E)
// Space Complexity : O(V+E)

#include <bits/stdc++.h>
/***************************************************************************

        Class for graph node is as follows:

        class graphNode
        {
                public:
                int data;
        vector<graphNode *> neighbours;
        graphNode()
        {
                data = 0;
                neighbours = vector<graphNode *>();
        }

        graphNode(int val)
        {
                data = val;
                neighbours = vector<graphNode *>();
        }

        graphNode(int val, vector<graphNode *> neighbours)
        {
                data = val;
                this->neighbours = neighbours;
        }
        };

******************************************************************************/
unordered_map<graphNode *, graphNode *> v;
graphNode *cloneGraph(graphNode *node)
{
    if (!node)
        return NULL;
    if (!v.count(node))
    {
        v[node] = new graphNode(node->data, {});
        for (auto &i : node->neighbours)
        {
            v[node]->neighbours.push_back(cloneGraph(i));
        }
    }
    return v[node];
}