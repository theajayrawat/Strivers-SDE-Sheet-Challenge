// Time Complexity: O(N)
// Space Complexity: O(K)

#include <bits/stdc++.h>
vector<int> countDistinctElements(vector<int> &arr, int k)
{
    // Write your code here
    unordered_map<int, int> mp;
    vector<int> ans;
    for (int i = 0; i < k; i++)
    {
        mp[arr[i]]++;
    }
    ans.push_back(mp.size());

    for (int i = k; i < arr.size(); i++)
    {
        int r = arr[i - k];
        if (mp[r] > 1)
            mp[r]--;
        else
            mp.erase(r);
        mp[arr[i]]++;
        ans.push_back(mp.size());
    }

    return ans;
}
