// Time Complexity: O(N)
// Space Complexity: O(1)

#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n)
{
    // Write your code here.
    int el;
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (cnt == 0)
        {
            cnt = 1;
            el = arr[i];
        }
        else if (arr[i] == el)
            cnt++;
        else
            cnt--;
    }

    int cnt1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == el)
            cnt1++;
    }

    if (cnt1 > (n / 2))
        return el;
    return -1;
}