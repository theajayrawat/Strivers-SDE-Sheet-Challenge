// Time Complexity: O(N*M)
// Space Complexity: O(N*M)

#include <bits/stdc++.h>
int f(int ind, int pre, vector<int> &arr, vector<vector<int>> &dp)
{
    if (ind == arr.size())
        return 0;
    if (dp[ind][pre + 1] != -1)
        return dp[ind][pre + 1];
    int notTake = f(ind + 1, pre, arr, dp);
    int take = INT_MIN;
    if (pre == -1 || arr[pre] < arr[ind])
    {
        take = arr[ind] + f(ind + 1, ind, arr, dp);
    }
    return dp[ind][pre + 1] = max(take, notTake);
}
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
    // Write your code here
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return f(0, -1, rack, dp);
}