// Time Complexity: O(M + N)
// Space Complexity: O(1)

bool searchMatrix(vector<vector<int>> &mat, int target)
{
    int n = mat.size();
    int m = mat[0].size();
    int i = 0;
    int j = m - 1;

    while (i >= 0 && i < n && j >= 0 && j < m)
    {
        if (mat[i][j] > target)
            j--;
        else if (mat[i][j] < target)
            i++;
        else
            return true;
    }
    return false;
}