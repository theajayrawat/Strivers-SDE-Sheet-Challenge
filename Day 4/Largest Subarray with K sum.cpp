// Time Complexity: O(N)
// Space Complexity: O(N)

#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector<int> arr)
{

    // Write your code here
    int sum = 0;
    int ans = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (mp.find(sum) != mp.end())
        {
            ans = max(ans, i - mp[sum]);
        }
        else
            mp[sum] = i;
        if (sum == 0)
            ans = max(ans, i + 1);
    }

    return ans;
}