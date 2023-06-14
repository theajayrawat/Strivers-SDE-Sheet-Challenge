// Time Complexity : O(NlogN)
// Space Complexity: O(1)

#include <bits/stdc++.h>
bool isPossible(vector<int> &A, long long time, int days)
{
    long long cnt = 0;
    long long sumAllocated = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (sumAllocated + A[i] > time)
        {
            cnt++;
            sumAllocated = A[i];
            if (sumAllocated > time)
                return false;
        }
        else
        {
            sumAllocated += A[i];
        }
    }
    if (cnt < days)
        return true;
    return false;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time)
{
    // Write your code here.
    if (n > m)
        return -1;
    long long low = time[0];
    long long high = 0;
    // to find minimum value and sum of all time
    for (int i = 0; i < m; i++)
    {
        high = high + time[i];
        if (low > time[i])
            low = time[i];
    }
    // binary search
    while (low <= high)
    {
        long long mid = (low + high) >> 1;
        if (isPossible(time, mid, n))
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}