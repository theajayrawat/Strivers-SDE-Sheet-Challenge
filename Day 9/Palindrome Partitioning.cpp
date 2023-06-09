// Time Complexity: O( (2^n)*k*(n)) “k”:average space for the Palindrome string
// Space Complexity: O(k * x)  “x":combination

#include <bits/stdc++.h>
bool isPalindrome(string s, int i, int j)
{

    while (i <= j)
    {
        if (s[i++] != s[j--])
            return false;
    }

    return true;
}
void dfs(vector<vector<string>> &ans, vector<string> &str, string s, int i)
{
    if (i == s.size())
    {
        ans.push_back(str);
        return;
    }

    for (int j = i; j < s.size(); j++)
    {
        if (isPalindrome(s, i, j))
        {
            str.push_back(s.substr(i, j - i + 1));
            dfs(ans, str, s, j + 1);
            str.pop_back();
        }
    }
}
vector<vector<string>> partition(string &s)
{
    // Write your code here.
    vector<vector<string>> ans;
    vector<string> str;
    dfs(ans, str, s, 0);
    return ans;
}