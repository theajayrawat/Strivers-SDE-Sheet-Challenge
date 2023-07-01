// Time Complexity: O(N*M)
// Space Complexity: O(N*M)

#include <bits/stdc++.h>

int helper(int m, int n, int i, int j, vector<vector<int>> &dp,
           vector<vector<int>> &grid)
{
    if (i > m - 1 || j > n - 1)
        return INT_MAX;
    if (i == m - 1 && j == n - 1)
        return grid[i][j];
    if (dp[i][j] != -1)
        return dp[i][j];
    int down = helper(m, n, i + 1, j, dp, grid);
    int right = helper(m, n, i, j + 1, dp, grid);
    return dp[i][j] = grid[i][j] + min(down, right);
}
int minSumPath(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return helper(m, n, 0, 0, dp, grid);
}