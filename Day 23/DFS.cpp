// Time Complexity: O(V + E)
// Space Complexity: O(V + E)
// Where 'V' is the number of vertex and 'E' is the number of edges in graph.

void dfs(int node, unordered_map<int, list<int>> &adjlist,
         vector<int> &visited, vector<int> &component)
{

    component.push_back(node);

    visited[node] = true;

    // harr connected node ke liye recursive call

    for (auto i : adjlist[node])
    {

        if (!visited[i])
        {

            dfs(i, adjlist, visited, component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)

{

    // prepairing adjlist

    unordered_map<int, list<int>> adjlist;

    for (int i = 0; i < edges.size(); i++)
    {

        int u = edges[i][0];

        int v = edges[i][1];

        adjlist[u].push_back(v);

        adjlist[v].push_back(u);
    }

    vector<vector<int>> ans;

    vector<int> visited(V, false);

    // traversing all vetices

    for (int i = 0; i < V; i++)
    {

        if (!visited[i])
        {

            vector<int> component;

            dfs(i, adjlist, visited, component);

            ans.push_back(component);
        }
    }

    return ans;
}