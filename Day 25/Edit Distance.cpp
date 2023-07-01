// Time Complexity: O(N*M)
// Space Complexity: O(N*M)

int editDistanceUtil(string &S1, string &S2, int i, int j, vector<vector<int>> &dp)
{

    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (S1[i] == S2[j])
        return dp[i][j] = 0 + editDistanceUtil(S1, S2, i - 1, j - 1, dp);

    // Minimum of three choices
    int rep = editDistanceUtil(S1, S2, i - 1, j - 1, dp);
    int del = editDistanceUtil(S1, S2, i - 1, j, dp);
    int ins = editDistanceUtil(S1, S2, i, j - 1, dp);

    return dp[i][j] = 1 + min(rep, min(del, ins));
}
int editDistance(string str1, string str2)
{
    // write you code here
    int n = str1.size();
    int m = str2.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));
    return editDistanceUtil(str1, str2, n - 1, m - 1, dp);
}