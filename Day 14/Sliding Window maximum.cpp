// Time Complexity: O(N)
// Space Complexity: O(K)

#include <bits/stdc++.h>
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    //    Write your code here.
    int n = nums.size();
    vector<int> ans;
    int maxValue = INT_MIN;
    int index = 0;
    for (int i = 0; i < k; i++)
    {
        if (maxValue < nums[i])
        {
            maxValue = nums[i];
            index = i;
        }
    }
    ans.push_back(maxValue);
    for (int i = k; i < n; i++)
    {
        if (maxValue < nums[i])
        {
            maxValue = nums[i];
            index = i;
        }
        if (index == i - k)
        {
            maxValue = INT_MIN;
            for (int j = i - k + 1; j <= i; j++)
            {
                if (maxValue < nums[j])
                {
                    maxValue = nums[j];
                    index = j;
                }
            }
        }
        ans.push_back(maxValue);
    }

    return ans;
}
