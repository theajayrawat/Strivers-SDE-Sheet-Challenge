// Time Complexity: O(2^n)
// Space Complexity: O(2^n)

#include <bits/stdc++.h>
void help(vector<vector<int>> &v, vector<int> &nums, vector<int> temp, int i, int n)
{
    v.push_back(temp);
    for (int j = i; j < n; j++)
    {
        if (j != i && nums[j] == nums[j - 1])
            continue;
        temp.push_back(nums[j]);
        help(v, nums, temp, j + 1, n);
        temp.pop_back();
    }
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>> v;
    vector<int> temp;
    sort(arr.begin(), arr.end());
    help(v, arr, temp, 0, n);
    return v;
}