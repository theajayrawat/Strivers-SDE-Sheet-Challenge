// Time Complexity: O(N)
// Space Complexity: O(1)

#include <bits/stdc++.h>
int findMinimumCoins(int amount)
{
    // Write your code here
    int ans = 0;
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n=coins.size();
    for (int i = n - 1; i >= 0; i--)
    {
        while (amount >= coins[i])
        {
            amount -= coins[i];
            ans++;
        }
    }

    return ans;
}