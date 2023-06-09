// Time Complexity: (2^n log(2^n))
// Space Complexity: O(2^n)

#include <bits/stdc++.h>
void help(vector<int> &v, int sum, vector<int> &num, int i)
{
    if (i == num.size())
    {
        v.push_back(sum);
        return;
    }
    // pick
    help(v, sum + num[i], num, i + 1);
    // not pick
    help(v, sum, num, i + 1);
}
vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    vector<int> v;
    int sum = 0;
    help(v, sum, num, 0);
    sort(v.begin(), v.end());
    return v;
}