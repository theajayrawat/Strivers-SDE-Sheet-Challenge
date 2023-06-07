// Time Complexity: O(N)
// Space Complexity: O(N)

#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n)
{
    // Write your code here.
    if (arr.empty())
        return 0;
    unordered_set<int> record(arr.begin(), arr.end());
    int res = 1;
    for (int n : arr)
    {
        if (record.find(n - 1) == record.end())
        {
            int cnt = 0;
            while (record.find(n) != record.end())
            {
                cnt++;
                n++;
            }
            res = max(res, cnt);
        }
    }
    return res;
}