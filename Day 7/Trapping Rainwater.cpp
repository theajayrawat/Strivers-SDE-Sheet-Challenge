// Time Complexity: O(N)
// Space Complexity: O(1)

#include <bits/stdc++.h>
long getTrappedWater(long *arr, int n)
{
    // Write your code here.
    long ans = 0;
    int i = 0, j = n - 1;
    long rightMax = 0, leftMax = 0;
    while (i <= j)
    {
        if (arr[i] < arr[j])
        {
            if (arr[i] > leftMax)
            {
                leftMax = arr[i];
            }
            else
                ans += leftMax - arr[i];
            i++;
        }
        else
        {
            if (arr[j] > rightMax)
            {
                rightMax = arr[j];
            }
            else
                ans += rightMax - arr[j];
            j--;
        }
    }
    return ans;
}