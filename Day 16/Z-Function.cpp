// Time Complexity: O(N+M)
//  Space Complexity: O(M)

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

int zAlgorithm(string s, string p, int n, int m)
{
    // Write your code here
    if (n < m)
        return -1;

    if (n == m)
    {
        if (s == p)
            return true;
        else
            return false;
    }

    vector<int> prefix = kmp(p, m);

    int i = 0, j = 0, ans = 0;

    while (i < n)
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
        if (j == m)
            ans++;
    }

    return ans;
}