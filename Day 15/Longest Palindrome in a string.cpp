// Time Complexity: O(N^2)
//  Space Complexity: O(1)

string longestPalinSubstring(string s)
{
    // Write your code here.
    int n = s.size();
    string res;
    int resLen = 0;

    for (int i = 0; i < n; i++)
    {
        // odd length;
        int l = i, r = i;
        while (l >= 0 && r < n && s[l] == s[r])
        {
            if (r - l + 1 > resLen)
            {
                resLen = r - l + 1;
                res = s.substr(l, resLen);
            }
            l--;
            r++;
        }

        // even length
        l = i, r = i + 1;
        while (l >= 0 && r < n && s[l] == s[r])
        {
            if (r - l + 1 > resLen)
            {
                resLen = r - l + 1;
                res = s.substr(l, resLen);
            }
            l--;
            r++;
        }
    }

    return res;
}