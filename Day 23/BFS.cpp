// Time complexity: O((V * log(V)) + E)
// Space complexity: O(V+E)

#include <bits/stdc++.h>
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    unordered_map<int, set<int>> adjlist;

    for (int i = 0; i < edges.size(); i++)
    {

        int u = edges[i].first;

        int v = edges[i].second;

        adjlist[u].insert(v);

        adjlist[v].insert(u);
    }

    vector<int> vis(vertex, false);
    vector<int> bfs;
    for (int i = 0; i < vertex; i++)
    {
        queue<int> q;
        if (!vis[i])
        {
            q.push(i);
            vis[i] = true;

            while (!q.empty())
            {

                int node = q.front();
                q.pop();
                bfs.push_back(node);

                for (auto it : adjlist[node])
                {
                    if (!vis[it])
                    {
                        vis[it] = true;
                        q.push(it);
                    }
                }
            }
        }
    }
    return bfs;
}