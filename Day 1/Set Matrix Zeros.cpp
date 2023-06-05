// Time Complexity: O(N^2)
// Space Complexity: O(N)

#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
    // Write your code here.
    set<int> row;
    set<int> col;

    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                row.insert(i);
                col.insert(j);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (row.find(i) != row.end())
        {
            for (int j = 0; j < m; j++)
                matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (col.find(i) != col.end())
        {
            for (int j = 0; j < n; j++)
                matrix[j][i] = 0;
        }
    }
}