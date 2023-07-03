// Time Complexity: O(N^2)
// Space Complexity: O(N)

#include <bits/stdc++.h>
bool wordBreakMemo(string &s, set<string> &word_set, int start, vector<int> &memo)
{
    if (start == s.length())
    {
        return true;
    }
    if (memo[start] != -1)
    {
        return memo[start];
    }
    for (int end = start + 1; end <= s.length(); end++)
    {
        if (word_set.find(s.substr(start, end - start)) != word_set.end() &&
            wordBreakMemo(s, word_set, end, memo))
        {
            return memo[start] = true;
        }
    }
    return memo[start] = false;
}
bool wordBreak(vector<string> &arr, int n, string &target)
{
    // Write your code here.
    set<string> word_set(arr.begin(), arr.end());
    vector<int> memo(target.length(), -1);
    return wordBreakMemo(target, word_set, 0, memo);
}