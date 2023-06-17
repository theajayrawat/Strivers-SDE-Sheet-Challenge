// Time Complexity: O ( n x n )
// Space Complexity: O ( n x n )

#include <bits/stdc++.h>
int minTimeToRot(vector<vector<int>> &grid, int n, int m)
{
    // Write your code here.
    if (grid.empty())
        return 0;
    int days = 0;
    queue<pair<int, int>> rotten;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (grid[i][j] == 2)
                rotten.push({i, j});
        }
    }

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    while (!rotten.empty())
    {
        int k = rotten.size();
        while (k--)
        {
            int x = rotten.front().first, y = rotten.front().second;
            rotten.pop();
            for (int i = 0; i < 4; ++i)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] != 1)
                    continue;
                grid[nx][ny] = 2;
                rotten.push({nx, ny});
            }
        }
        if (!rotten.empty())
            days++;
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (grid[i][j] == 1)
                return -1;
        }
    }
    return days;
}