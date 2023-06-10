// Time Complexity: O(N! X N^4)
// Space Complexity: O(N^2)

#include <bits/stdc++.h>


    bool isSafe(vector<vector<int>> &board,int r,int c,int n)
    {
        for(int i=0; i<c; i++)
        {
            if(board[r][i]==1)
                return false;
        } 
        int i=r,j=c;
        while(i>0 && j>0)
        {
            if(board[i-1][j-1]==1)
                return false;
            i--;
            j--;
        }
        i=r,j=c;
        while(i<n-1 && j>0)
        {
            if(board[i+1][j-1]==1)
                return false;
            i++;
            j--;
        }
        return true;
    }


void solve(int col, int n, vector<vector<int>> &matrix, vector<vector<int>> &ans)

{

    if (col == n)
    {

        vector<int> temp;

        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < n; j++)
            {

                temp.push_back(matrix[i][j]);
            }
        }

        ans.push_back(temp);

        return;
    }

     for(int row=0;row<n;row++){
        if(isSafe(matrix, row, col, n)) {
            matrix[row][col]=1;
            solve(col+1,n,matrix,ans);
            matrix[row][col]=0;
       }
    }
}

vector<vector<int>> solveNQueens(int n)
{

    vector<vector<int>> matrix(n, vector<int>(n, 0));

    vector<vector<int>> ans;

    solve(0, n, matrix, ans);

    return ans;

    // Write your code here.
}