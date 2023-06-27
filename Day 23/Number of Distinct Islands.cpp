// Time Complexity: O(N * M)
// Space Complexity: O(N * M)

void help(int **grid, int i, int j, int n, int m)
{
    if (i < 0 || j < 0 || i == n || j == m ||
        grid[i][j] == 0)
        return;

    grid[i][j] = 0;
    help(grid, i + 1, j, n, m);
    help(grid, i, j + 1, n, m);
    help(grid, i - 1, j, n, m);
    help(grid, i, j - 1, n, m);
    help(grid, i + 1, j + 1, n, m);
    help(grid, i - 1, j - 1, n, m);
    help(grid, i - 1, j + 1, n, m);
    help(grid, i + 1, j - 1, n, m);
}
int getTotalIslands(int **arr, int n, int m)
{
    // Write your code here.
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
            {
                cnt++;
                help(arr, i, j, n, m);
            }
        }
    }

    return cnt;
}
