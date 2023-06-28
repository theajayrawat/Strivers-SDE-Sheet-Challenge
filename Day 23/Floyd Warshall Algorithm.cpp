// Time Complexity: O(V^3)
// Space Complexity: O(V^2)

int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<vector<int>> mat(n, vector<int>(n, 10e8));

    for (int i = 0; i < n; i++)
        mat[i][i] = 0;

    for (auto i : edges)
    {
        int u = i[0] - 1, v = i[1] - 1, wt = i[2];
        mat[u][v] = wt;
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][k] != 1e9 && mat[k][j] != 1e9)
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }
    }

    return mat[src - 1][dest - 1];
}
