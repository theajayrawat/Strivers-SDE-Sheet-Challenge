// Time Complexity: O(ElogV)
// Space Complexity: O(V+E)

#include <bits/stdc++.h>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    // Write your code here.
    vector<pair<int, int>> adj[vertices];
    for (auto it : vec)
    {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dist(vertices, INT_MAX);

    dist[source] = 0;

    pq.push({0, source});
    while (!pq.empty())
    {

        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int dis = it.first;

        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int edW = it.second;

            if (dis + edW < dist[adjNode])
            {
                dist[adjNode] = dis + edW;
                pq.push({dis + edW, adjNode});
            }
        }
    }

    return dist;
}
