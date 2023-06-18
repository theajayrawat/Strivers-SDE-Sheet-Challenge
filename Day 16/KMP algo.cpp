// Time Complexity: O(N+M)
//  Space Complexity: O(N)

#include <bits/stdc++.h>
vector<int> kmp(string s, int n)
{
    vector<int> p(n, 0);

    for (int i = 1; i < n; i++)
    {
        int j = p[i - 1];

        while (j > 0 && s[i] != s[j])
            j = p[j - 1];

        if (s[i] == s[j])
            j++;

        p[i] = j;
    }

    return p;
}
bool findPattern(string p, string s)
{
    // Write your code here.
    int m = s.size();
    int n = p.size();

    if (n > m)
        return -1;

    if (n == m)
    {
        if (s == p)
            return true;
        else
            return false;
    }

    vector<int> prefix = kmp(p, n);

    int i = 0, j = 0;

    while (i < m)
    {
        if (s[i] == p[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j != 0)
                j = prefix[j - 1];
            else
                i++;
        }
        if (j == n)
            return true;
    }

    return false;
}