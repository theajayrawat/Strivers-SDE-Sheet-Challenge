// Time Complexity: O(N)
//  Space Complexity: O(1)

#include <bits/stdc++.h>
int compareVersions(string a, string b)
{
    // Write your code here
    int n = a.size(), m = b.size();
    int i = 0, j = 0;
    while (i < n || j < m)
    {
        while (i < n and a[i] == '0')
            i++;
        while (j < m and b[j] == '0')
            j++;

        long long num1 = 0, num2 = 0;

        while (i < n and a[i] != '.')
            num1 = (num1 * 10) + (a[i++] - '0');

        while (j < m and b[j] != '.')
            num2 = (num2 * 10) + (b[j++] - '0');

        if (num1 > num2)
            return 1;
        else if (num1 < num2)
            return -1;

        i++, j++;
    }

    return 0;
}