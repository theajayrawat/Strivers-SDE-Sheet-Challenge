// Time Complexity: O(N^2)
// Space Complexity: O(N)

#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s)
{

    int cnt = 0;

    vector<vector<int>> ans;

    unordered_map<int, int> mp;

    for (int i = 0; i < arr.size(); i++)
    {

        if (mp[s - arr[i]])
        {

            int val = mp[s - arr[i]];

            vector<int> output;

            while (val--)
            {

                output.push_back(min(arr[i], s - arr[i]));

                output.push_back(max(arr[i], s - arr[i]));

                ans.push_back(output);
            }
        }

        mp[arr[i]]++;
    }

    sort(ans.begin(), ans.end());

    return ans;
}