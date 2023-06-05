// Time Complexity: O(N^2)
// Space Complexity: O(N)

#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n)
{
    // Write your code here.
    vector<vector<long long int>> ans;

    for (int i = 0; i < n; i++)
    {
        vector<long long int> temp;
        for (int j = 0; j <= i; j++)
        {
            if (i == j || j == 0)
                temp.push_back(1);
            else
            {
                temp.push_back(ans[i - 1][j] + ans[i - 1][j - 1]);
            }
        }
        ans.push_back(temp);
    }

    return ans;
}
