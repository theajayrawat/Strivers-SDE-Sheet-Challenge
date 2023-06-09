// Time Complexity: O(2^n*k) “k”:average space for the temp;
// Space Complexity:O(k*x) “x":combination



#include <bits/stdc++.h>
void help(vector<vector<int>> &v, vector<int> &candidates, vector<int> temp, int i, int target)
{
    if (target == 0)
    {
        v.push_back(temp);
        return;
    }
    else if (target < 0)
    {
        return;
    }

    for (int j = i; j < candidates.size(); j++)
    {
        if (i != j && candidates[j] == candidates[j - 1])
            continue;
        temp.push_back(candidates[j]);
        help(v, candidates, temp, j + 1, target - candidates[j]);
        temp.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
    // Write your code here.
    vector<vector<int>> v;
    vector<int> temp;
    sort(arr.begin(), arr.end());
    help(v, arr, temp, 0, target);
    return v;
}