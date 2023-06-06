// Time Complexity: O(log n)
// Space Complexity: O(1)

#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m)
{
    // Write your code here.
    long long ans = 1;
    long long xx = x;
    while (n)
    {
        if (n % 2)
        {
            ans = ((ans) % m * (xx) % m) % m;
            n--;
        }
        else
        {
            xx = ((xx) % m * (xx) % m) % m;
            n = n >> 1;
        }
    }
    
    return (int)(ans % m);
}