// Time Complexity: O(N^2)
// Space Complexity: O(3*No of Triplet) 

#include <bits/stdc++.h>
vector<vector<int>> findTriplets(vector<int> arr, int n, int K)
{
    // Write your code here.
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        while (i > 0 && arr[i] == arr[i - 1])
            i++;

        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum == K)
            {
                ans.push_back({arr[i], arr[j], arr[k]});
                j++;
                k--;

                // skip the duplicates:
                while (j < k && arr[j] == arr[j - 1])
                    j++;
                while (j < k && arr[k] == arr[k + 1])
                    k--;
            }
            else if (sum < K)
                j++;
            else
                k--;
        }
    }

    return ans;
}