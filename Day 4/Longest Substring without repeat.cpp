// Time Complexity: O(N)
// Space Complexity: O(N)

#include <bits/stdc++.h>
int uniqueSubstrings(string input)
{
    int n = input.size();
    int ans = 0;
    unordered_map<char, int> mp;
    int firstIndex = 0;

    for (int lastIndex = 0; lastIndex < n; lastIndex++)
    {
        while (mp.find(input[lastIndex]) != mp.end())
        {
            mp.erase(input[firstIndex]);
            firstIndex++;
        }
        mp[input[lastIndex]]++;
        ans = max(ans, lastIndex - firstIndex + 1);
    }

    return ans;
}