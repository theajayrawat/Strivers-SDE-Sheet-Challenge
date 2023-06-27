// Time complexity: O(V+E)
// Space complexity: O(V+E)

bool dfs(unordered_map<int, vector<int>> &adj, vector<int> &inRecursion,
         vector<int> &visited, int u)
{
    visited[u] = true;
    inRecursion[u] = true;

    for (auto &v : adj[u])
    {
        if (!visited[v] && dfs(adj, inRecursion, visited, v))
            return true;
        else if (inRecursion[v])
            return true;
    }

    inRecursion[u] = false;
    return false;
}
int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    // Write your code here.
    unordered_map<int, vector<int>> adj;
    vector<int> visited(n, false);
    vector<int> inRecursion(n, false);

    for (auto &vec : edges)
    {
        int u = vec.first;
        int v = vec.second;
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && dfs(adj, inRecursion, visited, i))
            return true;
    }

    return false;
}