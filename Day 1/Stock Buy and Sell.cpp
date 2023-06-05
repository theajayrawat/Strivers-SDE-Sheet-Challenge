// Time Complexity: O(N)
// Space Complexity: O(1)

#include <bits/stdc++.h>

int maximumProfit(vector<int> &prices)
{
    // Write your code here.
    int profit = INT_MIN;
    int mini = INT_MAX;
    for (int i = 0; i < prices.size(); i++)
    {
        mini = min(mini, prices[i]);
        profit = max(profit, prices[i] - mini);
    }

    return profit;
}