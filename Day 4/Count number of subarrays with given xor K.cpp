// Time Complexity: O(N)
// Space Complexity: O(N)

#include <bits/stdc++.h>

int subarraysXor(vector<int> &nums, int x)
{
    //    Write your code here.
    unordered_map<int, int> mp;
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum ^= nums[i];
        if (sum == x)
            ans++;
        int a = sum ^ x;
        if (mp.find(a) != mp.end())
        {
            ans += mp[a];
        }
        mp[sum]++;
    }
    return ans;
}