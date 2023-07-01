// Time Complexity: O(N*N*N)
// Space Complexity: O(N*N)

#include <bits/stdc++.h>

#include <bits/stdc++.h>

int helper(vector<int> &arr, int start, int end, vector<vector<int>> &dp)
{
    if (start == end - 1)
    {
        return dp[start][end] = 0;
    }
    if (dp[start][end] != -1)
    {
        return dp[start][end];
    }
    int mini = INT_MAX;
    for (int i = start + 1; i < end; i++)
    {
        int ans = helper(arr, start, i, dp) + helper(arr, i, end, dp) + arr[start] * arr[i] * arr[end];
        mini = min(mini, ans);
    }
    return dp[start][end] = mini;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));
    return helper(arr, 0, N - 1, dp);
}
