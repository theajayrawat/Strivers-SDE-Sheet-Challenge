// Time Complexity: O(N)
// Space Complexity: O(N)

#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    // Write your code here
    int i, j, left, right, top, bottom, k, temp;

    left = 0;
    top = 0;
    right = m - 1;
    bottom = n - 1;

    while (top < bottom && left < right)

    {

        temp = mat[top][left];

        for (i = left + 1; i <= right; i++)

        {

            k = mat[top][i];

            mat[top][i] = temp;

            temp = k;
        }

        top++;

        for (i = top; i <= bottom; i++)

        {

            k = mat[i][right];

            mat[i][right] = temp;

            temp = k;
        }

        right--;

        for (i = right; i >= left; i--)

        {

            k = mat[bottom][i];

            mat[bottom][i] = temp;

            temp = k;
        }

        bottom--;

        for (i = bottom; i >= top; i--)

        {

            k = mat[i][left];

            mat[i][left] = temp;

            temp = k;
        }

        left++;

        mat[top - 1][left - 1] = temp;
    }
}