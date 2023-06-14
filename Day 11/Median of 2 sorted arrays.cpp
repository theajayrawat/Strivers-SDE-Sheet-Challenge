// Time Complexity : O(log(min(m,n)))
// Space Complexity: O(1)

double median(vector<int> &a, vector<int> &b)
{
    // Write your code here.
    int n = b.size();
    int m = a.size();
    if (m > n)
        return median(b, a);

    int low = 0;
    int high = m;
    int medianPos = ((m + n) + 1) / 2;
    while (low <= high)
    {
        int cut1 = (low + high) >> 1;
        int cut2 = medianPos - cut1;

        int l1 = (cut1 == 0) ? INT_MIN : a[cut1 - 1];
        int l2 = (cut2 == 0) ? INT_MIN : b[cut2 - 1];
        int r1 = (cut1 == m) ? INT_MAX : a[cut1];
        int r2 = (cut2 == n) ? INT_MAX : b[cut2];

        if (l1 <= r2 && l2 <= r1)
        {
            if ((m + n) % 2 != 0)
                return max(l1, l2);
            else
                return (max(l1, l2) + min(r1, r2)) / 2.0;
        }
        else if (l1 > r2)
            high = cut1 - 1;
        else
            low = cut1 + 1;
    }
    return 0.0;
}