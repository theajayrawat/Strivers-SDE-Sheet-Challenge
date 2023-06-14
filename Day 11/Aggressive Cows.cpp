// Time Complexity : O(N*log(M))
// Space Complexity: O(1)

bool isPossible(vector<int> &a, int cows, int minDist)
{
    int cntCows = 1;
    int lastPlacedCow = a[0];
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] - lastPlacedCow >= minDist)
        {
            cntCows++;
            lastPlacedCow = a[i];
        }
    }
    if (cntCows >= cows)
        return true;
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    sort(stalls.begin(), stalls.end());
    int low = 1, high = stalls[stalls.size() - 1] - stalls[0];

    while (low <= high)
    {
        int mid = (low + high) >> 1;

        if (isPossible(stalls, k, mid))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
}